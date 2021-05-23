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
vector<vector<ll>> edges;
vector<ll> parent(MAX),sz(MAX);
bool cycle;

void make_set(ll v)
{
    parent[v] = v;
    sz[v] = 1;
}

ll find_set(ll v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(sz[a]<sz[b])
            swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    pinakipb2;
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        edges.pb({u,v});
    }
    for(int i=0;i<MAX;i++)
    {
        make_set(i);
    }
    for(auto i:edges)
    {
        ll u = i[0];
        ll v = i[1];
        ll x = find_set(u);
        ll y = find_set(v);
        if(x==y)
        {
            cycle = true;
        }
        else
        {
            union_sets(u,v);
        }
    }
    if(cycle) cout<<"Cycle Present"<<endl;
    else cout<<"Cycle Absent"<<endl;
    
    return 0;
}

// INPUT :
// n m
// u v

// 4 4
// 0 1
// 1 2
// 2 3
// 3 0

// OUTPUT :
// Cycle Present

// INPUT :
// 4 2
// 0 1
// 2 3

// OUTPUT:
// Cycle Absent