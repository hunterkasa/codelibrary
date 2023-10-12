// https://codeforces.com/contest/1526/problem/C1
#include <bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define fr1( i, a, n )  for( long long i = a; i < n; i++ )
#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define rf( i, n )      for( long long i = n-1; i >= 0; i-- )
#define py              cout << "YES\n";
#define pyy             cout << "Yes\n";
#define pn              cout << "NO\n";
#define pnn             cout << "No\n";
#define all(v)          v.begin(),v.end()
#define pb              push_back
#define vll             vector<long long>
#define mll             map<long long,long long>
#define vpll            vector<pair<long long,long long>>
#define lb(v,x)         lower_bound(all(v),x)-v.begin()
#define ub(v,x)         upper_bound(all(v),x)-v.begin()
#define precision(a)    cout << fixed << setprecision(a) 
#define mem(x,y)        memset(x,y,sizeof(x))
#define pll             pair<ll,ll>
#define sr(a)           sort(all(a))
#define srg(a)          sort(all(a),greater<>())
#define re              return;
#define int long long
typedef long long ll;

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /*freopen("output.txt","w",stdout);*/
    #endif
}

ll dp[2002][2002];
ll a[2002];
ll INF = INT_MAX;

void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    int n;  cin >> n;
    fr ( i, n ) cin >> a[i];

    fr ( i, n+1 ) fr ( j, n+1 ) dp[i][j] = -1*(INF);    
    
    fr ( i, n+1 ) dp[i][0] = 0;

    for ( int i = 1; i <= n; i++ ){
        for ( int j = 1; j <= i; j++ ){
            if ( dp[i-1][j-1] + a[i-1] >= 0 )
                dp[i][j] = max( dp[i-1][j-1]+a[i-1], dp[i-1][j] );
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    for ( int i = n; i >= 0; i-- ){
        if ( dp[n][i] >= 0 ){
            cout << i; re
        }
    }

}
    
    
signed main(){
    class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    fast(); 
    ll tt = 1;
    // cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        solve();
    }      
    return 0;
}    



