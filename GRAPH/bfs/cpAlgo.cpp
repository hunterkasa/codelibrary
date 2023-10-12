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

bool isPrime( int n ) {
    if ( n == 1 ) return false; // by definition, 1 is not prime number
    if ( n == 2 ) return true; // the only one even prime
    for ( int i = 2; i * i <= n; ++i )
        if ( n%i == 0 ) return false;
    return true;
}



vll adj[1000];
int n,s;    
bool used[1000];
int d[1000], p[1000];

void bfs( int s ){
    queue<int> q;
    q.push(s);
    used[s] = 1;
    p[s] = -1;

    while( !q.empty() ){
        int v = q.front();
        q.pop();
        for( int u : adj[v] ){
            if ( !used[u] ){
                used[u] = 1;
                q.push(u);
                d[u] = d[v]+1;
                p[u] = v;
            }
        }
    } 
}

void travarseBfs(int u){
    if (!used[u]) {
        cout << "No path!";
    } else {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
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