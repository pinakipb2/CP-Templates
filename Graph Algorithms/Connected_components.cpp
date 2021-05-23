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
vector<ll> components;

ll get_comp(ll idx)
{
    if(vis[idx])
    {
        return 0;
    }
    vis[idx] = true;
    ll ans = 1;
    for(auto x:adj[idx])
    {
        if(!vis[x])
        {
            ans += get_comp(x);
            vis[x] = true;
        }
    }
    return ans;
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
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            components.pb(get_comp(i));
        }
    }
    
    cout<<components.size()<<endl;  // total number of connected components
    for(auto &x:components)  // number of nodes in each connected component
    {
        cout<<x<<" ";
    }
    
    return 0;
}

// INPUT :
// n m
// u v

// 5 3
// 0 1
// 2 3
// 0 4

// OUTPUT :
// 2
// 3 2