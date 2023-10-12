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
#define mem(x)        	memset(x,0,sizeof(x))
#define in(a,n)	        for(int i=0;i<n;i++) cin>>a[i];
#define si              set<int>
// #define INF             INT_MAX;
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

 
void fast(){
    io;
    #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        /*freopen("output.txt","w",stdout);*/
    #endif
}


ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
ll nCr(ll n, ll m){   ll s = 1;for (ll i = n - m + 1; i <= n; i++) {s = s * i / (i - n + m);  }return s;}


// #define int long long 
// #define inf 1e18

// const int nMax = 1e8;
// bitset<nMax> bit;
// vll primes;
// void seive(){bit.set();bit[0] = bit[1] = 0;for ( int i = 2; i * i <= nMax; i++ ){if (bit[i]) {for (int j = i * i; j <= nMax; j += i) bit[j] = 0;} }/*segmentedfor ( int i = 0; i < nMax; i++ ) if ( bit[i] )primes.pb(i);*/}

const int N = 20001;
int n, m;
vll a[N];
ll vis[N], col[N];

bool dfs( int node, int c ){
    vis[node] = 1;
    col[node] = c;
    for ( auto child : a[node] ){
        if ( !vis[child] ){
            bool res = dfs(child,c^1);
            if ( res == false )
                return false;
        } else 
        if ( col[node] == col[child] )
            return false;
        }
    
    return true;
}


void solve(){

    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    mem(col);
    mem(vis);
    fr ( i, N )
        a[i].clear();


    cin >> n >> m;

    fr ( i, m ){
        int x, y;   cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    bool f = true;

    for ( int i = 1; i <= n; i++ ){
        if ( !vis[i] ){
            bool res = dfs(i,0);
            if ( !res )
                f = false;
        }
    }

    if ( !f ){
        cout << "Suspicious bugs found!\n";
    } else {
        cout << "No suspicious bugs found!\n";
    }
    
    
}
    
    
signed main(){
    fast();
    class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    ll tt = 1;
    cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        cout << "Scenario #" << i++ << ":\n";
        solve();
    }      
}  