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

void DFS(ll source)
{
    vis[source] = true;
    cout<<source<<" ";
    for(auto x:adj[source])
    {
        if(!vis[x])
        {
            DFS(x);
        }
    }
}

void DFSDisconn()
{
    for(int i=0;i<m;i++)
    {
        if(!vis[i])
        {
            DFS(i);
        }
    }
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
        adj[v].pb(u);
    }
    ll source = 0; // traversal starts from source node
    DFS(source); // DFS on undirected graph and a source vertex
    
    DFSDisconn(); // DFS on disconnected graph
    
    return 0;
}

// DFS on undirected graph and a source vertex :
// INPUT :
// n m
// u v

// 5 7
// 0 1
// 0 2
// 2 3
// 1 3
// 1 4
// 3 4

// OUTPUT :
// 0 1 3 2 4


// DFS on disconnected graph :
// INPUT :
// n m
// u v

// 5 4
// 0 1
// 0 2
// 1 2
// 3 4

// OUTPUT :
// 0 1 2 3 4