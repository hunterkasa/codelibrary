#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <queue>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define REP( i, n )     for( long long i = 0; i < n; i++ )
#define FOR( i, a, b )  for( long long i = a; i <= b; i++ )
#define endl            '\n'
#define pb              push_back
#define ppb             pop_back
#define ANS(x)          cout << x << endl;
#define MAX             INT_MIN
#define MIN             INT_MAX
#define INF             1000000007
#define all(v)          v.begin(),v.end()
#define rall(v)         v.rbegin(),v.rend()
#define ff              first
#define ss              second
#define READ(x)         freopen(x,"r",stdin)
#define WRITE(x)        freopen(x,"w",stdout)
#define poy             cout << "YES\n";
#define pon             cout << "NO\n";
 
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<string>vs;
typedef long long int lli;
typedef vector<long long> vll;
typedef vector<pair<int , int>> pi;
typedef vector<pair<long , long>> pll;

const int MOD = 1e9 + 7;

// ll n, m, k, a, b, c, d, x, y, z, w, i, j, l, ans = 0, res = 0;
// string s;


void solve(){
    
    
    int n, val;
    cin >> n;
    vector<vector<int>> dp(n);
    
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j <= i; j++ ){
            cin >> val;
            dp[i].pb(val);
        }
    }
    
    for ( int i = n - 2; i >= 0; i-- ){
        for ( int j = 0; j <= i; j++ ){
            dp[i][j] += max( dp[i+1][j], dp[i+1][j+1]);
        }
    }
    cout << dp[0][0] << endl;
    
    
    
}

signed main(){
    
    io;
    // #ifndef ONLINE_JUDGE
    //     READ("a.txt");
    //     WRITE("a.txt");
    // #endif
    ll t = 1;
    // cin >> t;    
    while ( t-- ){
        solve();
    }
}