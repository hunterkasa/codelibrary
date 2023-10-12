// https://www.youtube.com/watch?v=zozEqVy-sKA&ab_channel=AshishKumar

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define REP( i, n )     for( long long i = 0; i < n; i++ )
#define py              cout << "YES\n";
#define pn              cout << "NO\n";
#define all(v)          v.begin(),v.end()

typedef long long ll;
const int MOD = 1e9 + 7;

bool search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}



vector<int> a[100000];
int visited[100000];

void dfs(int k){
    if(!visited[k]){
        visited[k] = 1;
        
        for ( int i = 0; i < a[k].size(); i++ ){
            if ( ! visited[a[k][i]] ){
                dfs(a[k][i]);
            }
        }
    }
}

void solve(){
    int n = 5;
    // nodes from 0 to 7 that is only 7 nodes are there
    
    while ( n-- ){
        //    directed graph
        int p , q;
        cin >> p >> q;
        a[p].push_back(q);
    }
    // can you go from l to m ?
    int l, m;
    cin >> l >> m;
    dfs(l);
    if ( visited[m] == l ){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    // dfs(0);
    // for ( int i = 0; i <= 7; i++ ){ cout << i <<":" << visited[i] << " "; }
}

signed main(){
    io;
    ll tt = 1;
    // cin >> tt;    
    while ( tt-- )  solve();
}