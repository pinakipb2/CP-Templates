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
    vector<vector<ll>> adj;
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj.pb({u,v,w});
    }
    vector<ll> dist(n,INT_MAX);
    ll source;
    cin>>source;
    dist[source] = 0;
    for(int i=0;i<n-1;i++)
    {
        for(auto x:adj)
        {
            ll u = x[0];
            ll v = x[1];
            ll w = x[2];
            dist[v] = min(dist[v],w + dist[u]);
        }
    }
    for(auto x:dist)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    
    return 0;
}

// INPUT :
// n m
// u v w
// source

// 5 8
// 1 2 3
// 3 2 5
// 1 3 2
// 3 1 1
// 1 4 2
// 0 2 4
// 4 3 -3
// 0 1 -1
// 0

// OUTPUT :
// 0 -1 2 -2 1