// https://www.spoj.com/problems/PT07Y/
#include <bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define fr1( i, a, n )  for( long long i = a; i < n; i++ )
#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define f( n )          for( long long i = 0; i < n; i++ )
#define rf( i, n )      for( long long i = n; i >= 0; i-- )
#define py              cout << "YES\n";
#define pyy             cout << "Yes\n";
#define pn              cout << "NO\n";
#define pnn             cout << "No\n";
#define all(v)          v.begin(),v.end()
#define rall(v)         v.rbegin(),v.rend()
#define pb              push_back
#define vll             vector<long long>
#define ss              second
#define ff              first
#define lb(v,x)         lower_bound(all(v),x)-v.begin()
#define ub(v,x)         upper_bound(all(v),x)-v.begin()
#define watch(x)        cerr << "\n" << (#x) << " is " << (x) << endl;
#define precision(a)    cout << fixed << setprecision(a) 
#define mem(x)        	memset(x,n,sizeof(x))
#define in(a,n)	        for(int i=0;i<n;i++) cin>>a[i];
#define si              set<int>
#define INF             INT_MAX;
// #define cerr            if(false)cerr
typedef long long int lli;
typedef long long ll;
typedef unsigned long long ull;

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args) { cout << t << " ";  print(forward<Args>(args)...); }

// Operator overloads 
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){ for (auto &it : v)  cin >> it;  return istream; }
 
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }


const int N = 1e5+10;
vll a[N];
ll vis[N];

void dfs( int x ){
    vis[x] = 1;
    for ( auto e : a[x] ){
        if (!vis[e]){
            dfs(e);
        }
    }
}


void solve(){

    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    int n, m;   cin >> n >> m;

    for ( int i = 0; i < m; i++ ){
        int x, y;cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    
    ll ans = 0;
    for ( int i = n; i >= 1; i-- )
        if ( !vis[i] ) dfs(i) , ans++;

    if ( ans == 1 && m == n-1 )
        py
    else pn


}
    
    
signed main(){
    class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    ll tt = 1;
    // cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        solve();
    }      
}  