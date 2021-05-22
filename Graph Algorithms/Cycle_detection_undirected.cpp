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
bool cycle;

bool dfs(ll source, ll parent)
{
    vis[source] = true;
    for(int x:adj[source])
    {
        if(x!=parent)
        {
            if(vis[x])
            {
                return true;
            }
            if(!vis[x] && dfs(x,source))
            {
                return true;
            }
        }
    }
    return false;
}

void isCycle()
{
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && dfs(i,-1))
        {
            cycle = true;
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
    
    isCycle();
    if(cycle) cout<<"Cycle Present"<<endl;
    else cout<<"Cycle Absent"<<endl;
    
    return 0;
}

// INPUT :
// n m
// u v

// 6 6
// 0 1
// 1 2
// 2 4
// 4 5
// 1 3
// 2 3

// OUTPUT :
// Cycle Present


// INPUT :
// 4 3
// 0 1
// 1 2
// 2 3

// OUTPUT :
// Cycle Absent