// https://atcoder.jp/contests/dp/tasks/dp_a
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
#define vpll            vector<pair<long long,long long>>
#define ss              second
#define ff              first
#define lb(v,x)         lower_bound(all(v),x)-v.begin()
#define ub(v,x)         upper_bound(all(v),x)-v.begin()
#define watch(x)        cerr << "\n" << (#x) << " is " << (x) << endl;
#define precision(a)    cout << fixed << setprecision(a) 
// #define mem(x,y)        memset(x,y,sizeof(x))
#define in(a,n)	        for(int i=0;i<n;i++) cin>>a[i];
#define pll             pair<ll,ll>
#define sr(a)           sort(all(a))
typedef long long ll;


void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /*freopen("output.txt","w",stdout);*/
    #endif
}

#define int long long

const int N = 2e5+2;
int a[N];
int dp[N];

int func( int i ){

    if ( i == 0 )   return 0;
    
    if ( dp[i] != -1 )  return dp[i];

    int cost = INT_MAX;
    // way 1 
    cost = min(cost, func(i-1)+abs(a[i]-a[i-1]));

    // way 2 
    if ( i > 1 )
        cost = min(cost, func(i-2)+abs(a[i]-a[i-2]));

    return dp[i] = cost;
}

void solve(){

    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];
    
    memset(dp,-1,sizeof(dp));
    int n;  cin >> n;
    fr ( i, n ) cin >> a[i];
    func(n-1);
    cout << dp[n-1];

    
}
    
    
signed main(){
    fast(); 
    // class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    ll tt = 1;
    // cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ":\n";
        solve();
    }      
}   