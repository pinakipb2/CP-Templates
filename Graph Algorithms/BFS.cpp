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

void BFS(ll source)
{
    queue<ll> q;
    vis[source] = true;
    q.push(source);
    while(!q.empty())
    {
        ll node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                vis[x] = true;
                q.push(x);
            }
        }
    }
}

void BFSDisconn()
{
    for(int i=0;i<m;i++)
    {
        if(!vis[i])
        {
            BFS(i);
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
    BFS(source); // BFS on undirected graph and a source vertex
    
    BFSDisconn(); // BFS on disconnected graph
    
    return 0;
}

// BFS on undirected graph and a source vertex :
// INPUT :
// n m
// u v

// 5 7
// 0 1
// 0 2
// 1 2
// 2 3
// 1 3
// 3 4
// 2 4

// OUTPUT :
// 0 1 2 3 4


// BFS on disconnected graph :
// INPUT :
// n m
// u v

// 7 7
// 0 1
// 0 2
// 2 3
// 1 3
// 4 5
// 5 6
// 4 6


// OUTPUT :
// 0 1 2 3 4 5 6