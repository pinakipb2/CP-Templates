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
ll cost;

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
        ll u,v,w;
        cin>>u>>v>>w;
        edges.pb({w,u,v});
    }
    sort(all(edges));
    for(int i=0;i<MAX;i++)
    {
        make_set(i);
    }
    for(auto i:edges)
    {
        ll w = i[0];
        ll u = i[1];
        ll v = i[2];
        ll x = find_set(u);
        ll y = find_set(v);
        if(x==y)
        {
            continue;
        }
        else
        {
            cout<<u<<" "<<v<<" "<<w<<endl;
            cost+=w;
            union_sets(u,v);
        }
    }
    cout<<cost<<endl;
    
    return 0;
}

// INPUT :
// n m
// u v w

// 8 9
// 1 2 5
// 2 3 6
// 4 3 2
// 1 4 9
// 3 5 5
// 5 6 10
// 6 7 7
// 7 8 1
// 8 5 1

// OUTPUT :
// 7 8 1
// 8 5 1
// 4 3 2
// 1 2 5
// 3 5 5
// 2 3 6
// 6 7 7
// 27