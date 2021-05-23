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

int main()
{
    pinakipb2;
    
    cin>>n>>m;
    vector<ll> dist(n+1,INT_MAX);
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    ll source;
    cin>>source;
    dist[source] = 0;
    set<pair<ll,ll>> st;
    st.insert({0,source});  // {wt,vertex}
    while(!st.empty())
    {
        auto x = *(st.begin());
        st.erase(x);
        for(auto i:adj[x.second])
        {
            if(dist[i.ff] > dist[x.ss] + i.ss)
            {
                st.erase({dist[i.ff],i.ff});
                dist[i.ff] = dist[x.ss] + i.ss;
                st.insert({dist[i.ff],i.ff});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]<INT_MAX)
        {
            cout<<dist[i]<<" ";
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    
    return 0;
}

// INPUT :
// n m
// u v w
// source

// 4 4
// 1 2 24
// 1 4 20
// 3 1 3
// 4 3 12
// 1

// OUTPUT :
// 0 24 3 15