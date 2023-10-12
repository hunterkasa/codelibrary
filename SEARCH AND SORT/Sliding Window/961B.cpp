// https://codeforces.com/contest/961/problem/B
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
#define rall(v)         v.rbegin(),v.rend()
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
#define rs(a)           sort(a.rbegin(), a.rend())

#define int long long
typedef long long ll;



void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /*freopen("output.txt","w",stdout);*/
    #endif
}



void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    int n, k;   cin >> n >> k;
    vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];
    vll t(n);   for ( int i = 0; i < n; i++ )  cin >> t[i];
    
    vll window;
    ll sum = 0;
    fr ( i, k ){
        if ( t[i] == 0 )
            sum += a[i];
    }
    window.pb(sum);

    for ( int i = 0; i < n-k; i++ ){
        if ( t[i] == 0 )
            sum -= a[i];
        if ( t[i+k] == 0 )
            sum += a[i+k];
        window.pb(sum);
    }

    srg(window);

    ll ans = 0;
    fr ( i, n ){
        if ( t[i] == 1 )    ans += a[i];
    }

    cout << ans + window[0] << endl;


    


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
}   