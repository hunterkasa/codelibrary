#include <bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
 
void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
 
 
 
 
 
 









const int N = 2e5+10;
int par[N];
int sz[N];

void make(){
    for ( int i = 0; i < N; i++ ){
        par[i] = i;
        sz[i] = 1;
    }
}
int find( int x ){
    if ( x == par[x] ) return x;
    return x = find(par[x]); 
}
void Union( int a , int b ){
    a = find(a);
    b = find(b);
    if ( a == b )   return;
    if ( sz[a] < sz[b] ) swap(a,b);
    par[b] = a; 
    sz[a] += sz[b];
}

void tohka(){

    int n;  cin >> n;
    make();

    for ( int i = 1; i <= n; i++ ){
        int x;  cin >> x;   
        Union(i,x);
    }

    map<int,vector<int>> mp;
    for ( int i = 1; i <= n; i++ ){
        // cout << find(i) << ' ';
        mp[find(i)].push_back(i);
    }

    cout << mp[1].size() << endl;
    for ( auto e : mp[1] )
        cout << e << ' ';

}
 
signed main(){
    fast(); 
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        tohka();
    }      
    return 0;
} 