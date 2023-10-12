#include <bits/stdc++.h>
#include <valarray>
using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define REP( i, a, n )  for( long long i = a; i <= n; i++ )
#define py              cout << "YES\n";
#define pn              cout << "NO\n";
#define all(v)          v.begin(),v.end()
#define rall(v)         v.rbegin(),v.rend()
#define pb              push_back
#define vll             vector<ll>
#define val             valarray<ll> 

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

bool search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}
ull gcd( ull a, ull b ){
    if ( b == 0 )    return a;
    return gcd(b,a%b);
}
// 1 upper bound lower bound multimap 
// 2 two pointer
// 3 set
// 4 sieve
// 5 min heap max heap

vector<int> subset;


void gs( int pos, int *arr, int len, int subset[5], int subsetdhukaise ){
    
    if ( pos == len ){
        for ( int i = 0; i < subsetdhukaise; i++ ){
            cout << subset[i] << " ";
        } cout << endl;
        return;
    }
    
    
    gs( pos+1, arr, len, subset, subsetdhukaise );
    subset[subsetdhukaise] = arr[pos];
    subsetdhukaise++;
    gs( pos+1, arr, len, subset, subsetdhukaise );
    
}
    

void solve(){
    // cout << "==================\n";
    // ll n,x;   cin >> n;
    // vector<ll> a(n),b(n+1); 
    // for ( auto &e: a )  cin >> e;
    
    int n = 5,m, k;
    int arr[5] = { 1,2,3,4,5 };
    int sst[5];
    for ( int i = 0; i < n; i++ )   sst[i] = 0;
    gs(0, arr, n, sst, 0);
    
}
    
    
     


signed main(){
    io;
    ll tt = 1;
    // cin >> tt;    
    while ( tt-- )        solve();
    
}