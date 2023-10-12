// http://www.shafaetsplanet.com/?p=604
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;
 
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP( i, n ) for( int i = 0; i < n; i++ )
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define ANS(x) cout << x << endl;
#define MAX INT_MIN
#define MIN INT_MAX
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int , int>> pi;
typedef vector<pair<long , long>> pll;


vll adj[1000];
int n,s;    
bool used[1000];
int d[1000], parent[1000], dist[1000];
bool vis[1000];

void bfs( int s ){
    
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis[s] = 1;

    while ( !q.empty() ){
        int u = q.front();
        q.pop();
        for ( auto v : adj[u] ){
            if ( !vis[v] ){
                vis[v] = 1;
                dist[v] = dist[u]+1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
}

void travarseBfs(int u){
    if (!parent[u]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
}

void solve(){
    
    
    
    
    
    
}

signed main(){
 
    io;
    
    // int t; 
    // cin >> t;
    
    // while ( t-- ){
        
        solve();
        
    // }
 
    
}