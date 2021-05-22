// Code Written by Pinaki Bhattacharjee (pinakipb2)
#include<bits/stdc++.h>
using namespace std;

// typedef
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

// #define
#define LOCAL
#define endl "\n"
#define PI 2*acos(0.0)
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mpr make_pair
#define all(x) (x).begin(),(x).end()
#define ppc __builtin_popcountll
#define pinakipb2 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// constants
const int MAX = 1e7 + 10;
const int MOD = (int) 1e9 + 7;

ll n,m;
vector<ll> adj[MAX];
bool vis[MAX];
vector<ll> topo;

void dfs(ll source)
{
    vis[source] = true;
    for(auto x:adj[source])
    {
        if(!vis[x])
        {
            dfs(x);
        }
    }
    topo.pb(source);
}

void topo_sort()
{
    topo.clear();
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    reverse(all(topo));
}

int main()
{
    pinakipb2;
    
    // n -> no. of nodes/vertex
    // m -> no. of edges
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    
    // Works for directed Graph
    // Here is an implementation which assumes that the Graph is "ACYCLIC"
    topo_sort(); // BEFORE USING THIS CHECK IF THE GRAPH IS "CYCLIC" OR NOT
    
    for(auto x:topo)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
}

// INPUT :
// n m
// u v

// 5 5
// 0 2
// 0 3
// 1 3
// 1 4
// 2 3

// OUTPUT :
// 1 4 0 2 3