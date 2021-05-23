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
vector<pair<ll,ll>> adj[MAX];
bool vis[MAX];
vector<ll> dist(MAX),parent(MAX);
ll cost;

void primsMST(ll source)
{
    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
    }
    set<pair<ll,ll>> st;
    dist[source] = 0;
    st.insert({0,source});
    while(!st.empty())
    {
        auto x = *(st.begin());
        st.erase(x);
        vis[x.ss] = true;
        ll u = x.ss;
        ll v = parent[x.ss];
        ll w = x.ff;
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;
        for(auto i:adj[x.ss])
        {
            if(vis[i.ff])
            {
                continue;
            }
            if(dist[i.ff] > i.ss)
            {
                st.erase({dist[i.ff],i.ff});
                dist[i.ff] = i.ss;
                st.insert({dist[i.ff],i.ff});
                parent[i.ff] = x.ss;
            }
        }
    }
}

int main()
{
    pinakipb2;
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    primsMST(0);
    cout<<cost<<endl;
    
    return 0;
}

// INPUT :
// n m
// u v w

// 4 5
// 0 1 10
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40

// OUTPUT :
// 0 0 0
// 2 0 5
// 1 0 10
// 3 1 2
// 17