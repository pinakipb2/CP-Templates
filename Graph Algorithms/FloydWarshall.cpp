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

int main()
{
    pinakipb2;
    
    vector<vector<ll>> adj ={ {0,5,INT_MAX,10},
                              {INT_MAX,0,3,INT_MAX},
                              {INT_MAX,INT_MAX,0,1},
                              {INT_MAX,INT_MAX,INT_MAX,0} };
    ll n = adj.size();
    vector<vector<ll>> dist = adj;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INT_MAX) cout<<"INF ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    // shortest dist b/w 1 and 3 -> dist[1][3]
    
    return 0;
}

// OUTPUT:
// 0 5 8 9
// INF 0 3 4
// INF INF 0 1
// INF INF INF 0