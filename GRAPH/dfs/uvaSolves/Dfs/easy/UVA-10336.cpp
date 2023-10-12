// https://vjudge.net/contest/203474#problem/F
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <valarray>
#include <set>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define REP( i, a, n )  for( long long i = a; i <= n; i++ )
#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define rf( i, n )      for( long long i = n; i >= 0; i-- )
#define py              cout << "YES\n";
#define pyy             cout << "Yes\n";
#define pn              cout << "NO\n";
#define pnn             cout << "No\n";
#define all(v)          v.begin(),v.end()
#define rall(v)         v.rbegin(),v.rend()
#define pb              push_back
#define vll             vector<ll>
#define ss              second
#define ff              first
#define ub(v,x)         upper_bound(all(v),x)-v.begin();
#define ul(v,x)         upper_bound(all(v),x)-v.begin();
#define watch(x)        cerr << "\n" << (#x) << " is " << (x) << endl;
// #define cerr            if(false)cerr
typedef long long int lli;
typedef long long ll;
typedef unsigned long long ull;

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /*freopen("output.txt","w",stdout);*/
    #endif
}

ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
//ll nCr(ll n, ll m){   ll s = 1;for (ll i = n - m + 1; i <= n; i++) {s = s * i / (i - n + m);  }return s;}
//ll powmod(ll a, ll b, ll p){a%=p;if(a==0)return 0;if (b==0) return 1;ll product = 1;while (b>0){if ( b & 1 ){   /* // b % 2 == 1 */product *= a;product %= p;b--;}a*=a;a%=p;b/=2;/* // b >> 1 */}return product;}
//ll inv(ll a, ll p){return powmod(a, p-2, p);}
//bool isPowerofN(long long num, long long base){long double log_num = (std::log((long double)num) / std::log((long double)base));long long x = std::floor(log_num);long long y = std::ceil(log_num);if (x == y)return true;else return false;}
//bool isPowerOf2(int x){return (n&&!(n&n-1));}
//const int N = 1000003;
// ll fact[1000003];
// ll nCk(ll n, ll k, ll p){return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;}

// const int nMax = 1e8;
// bitset<nMax> bit;
// vector<int> primes;
//void seive(){bit.set();bit[0] = bit[1] = 0;for ( int i = 2; i * i <= nMax; i++ ){if (bit[i]) {for (int j = i * i; j <= nMax; j += i) bit[j] = 0;} }/*segmentedfor ( int i = 0; i < nMax; i++ ) if ( bit[i] )primes.pb(i);*/}
//void segSeive(ll l, ll r){bool isPrime[r-l+1];for ( int i = 0; i < r-l+1; i++ )isPrime[i] = true;if ( l == 1 ) isPrime[0] = false;for ( int i = 0; primes[i]*primes[i] <= r; i++ ){int currentPrime = primes[i];ll base = (l/currentPrime)*currentPrime;if ( base < l )base += currentPrime;for ( ll j = base; j <= r; j+= currentPrime ){isPrime[j-l] = false;}if ( base == currentPrime ) isPrime[base-l] = true;} /* for ( int i = 0; i < r - l + 1; i++ )if ( isPrime[i] )cout << i+l << endl; */}

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m ;
char a[26][26];
int vis[26][26];

bool valid(int x, int y, char c){
    if ( x>=0 && x < n&&y>=0&&y<m&&a[x][y]==c&&!vis[x][y])
        return true;
    return false;
}

void dfs(int x, int y, char c){
    vis[x][y] = 1;
    fr(i,4){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if ( valid(newx,newy,c) ){
            dfs(newx,newy,c);
        }
    }
}

int cmp( pair<char,int> a, pair<char,int> b){ return a.second > b.second; }

void solve(){
    
    //ll n;   cin >> n;
    //vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i]; 

    // int t = 1;

    cin >> n >> m;
    int cnt = 0;
    memset(vis,0,sizeof(vis));
    fr(i,n){
        fr(j,m){
            cin >> a[i][j];
        }
    }
    map<char,int> mp;
    fr( i,n ){
        fr(j,m){
            if ( vis[i][j] == 0 ){
                char c = a[i][j];
                mp[c]++;
                dfs(i,j,c);
            } 
        }
    }
    
    /* map<char,int> :: iterator it;
    for ( it = mp.begin(); it != mp.end(); it++ ){
        cout << it->first << ": " << it->second << endl;
    } */
    
    vector<pair<char,int>> v(mp.begin(),mp.end());
    sort(all(v),cmp);
    fr ( i, v.size() ){
        cout << v[i].first << ": " << v[i].second << endl;
    }
    
}

    
    
int main(){
    class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    fast();
    ll tt = 1;
    cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        cout << "World #" << i++ << endl;
        // cout << "Case " << i++ << ": ";    
        solve();
    }      
}