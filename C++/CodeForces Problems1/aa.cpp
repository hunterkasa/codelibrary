#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>


template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

// template <typename T> T floor( T a, T b ){ return a/b; } // careful for negetive numbers
// template <typename T> T ceil( T a, T b ){ return (a+b-1)/b; }
// template <typename T> T sqrt( T x ){ T ans = 0;for (T k = 1 << 30; k != 0; k /= 2) {if ((ans + k) * (ans + k) <= x) {ans += k;}}return ans;}
// template <typename T> T sqr(T x) { T n = x * x ; return n ;}
// template <typename T> T pow(T B,T P){ if(P==0) return 1; if(P&1) return B*pow(B,P-1);  else return sqr(pow(B,P/2));}
// // Operator overloads
// template<typename T1, typename T2> /*cin >> pair<T1, T2>*/ istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
// template<typename T> /* // cin >> vector<T> */istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
// template<typename T1, typename T2> /* // cout << pair<T1, T2> */ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
// template<typename T> /* // cout << vector<T> */ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n)-1)

#define modulo(S, N) ((S) & (N-1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S-1)))
#define nearestPowerOfTwo(S) (1<<lround(log2(S)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S+1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S-1))

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T exgcd(T a,T b,T &x,T &y) {if(a<0){T d=exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> typename std::vector<T>::iterator insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);}
template <typename T> T isperfectsq(T x){ T n = sqrt(x); return ((n * n == x)?1:0);}

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}

// char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
// char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
// bool isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
// int strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
// string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
// vector<string> linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.pb(s);return v;}

// ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}
// ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
// ll nCr(ll n, ll m){   ll s = 1;for (ll i = n - m + 1; i <= n; i++) {s = s * i / (i - n + m);  }return s;}
// bool isPowerofN(long long num, long long base){long double log_num = (std::log((long double)num) / std::log((long double)base));long long x = std::floor(log_num);long long y = std::ceil(log_num);if (x == y)return true;else return false;}
// bool isPowerOf2(int x){return (n&&!(n&n-1));}

// ll powmod(ll a, ll b, ll p){a%=p;if(a==0)return 0;if (b==0) return 1;ll product = 1;while (b>0){if ( b & 1 ){   /* // b % 2 == 1 */product *= a;product %= p;b--;}a*=a;a%=p;b/=2;/* // b >> 1 */}return product;}
// const int N = 1000003;
// ll inv(ll a, ll p){return powmod(a, p-2, p);}
// ll fact[1000003];
// ll nCk(ll n, ll k, ll p){return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;}

// priority_queue <int, vector<int>, greater<int>> q;
// string w = string(n, '1');
// vector<vector<int>> a(n, vector<int>(m));
 
// const ll maxn = 1e5+10, mod = 8e18;
// template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
// ll ncr(ll n, ll m){   ll s = 1;for (ll i = n - m + 1; i <= n; i++) {s = s * i / (i - n + m);  }return s;}
// template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
// template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
 


// declare custom comparator with data structure
bool cmp( pair<int,int> &a, pair<int,int> &b ){
    if ( a.first == b.first )
        return a.second > b.second;
    return a.first < b.first;
}
priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(&cmp)> q(cmp);

const int nMax = 1e8;
bitset<nMax> bit;
vector<int> primes;
void seive(){
    bit.set();bit[0] = bit[1] = 0;
    for ( int i = 2; i * i <= nMax; i++ ){
        if (bit[i]) {
            for (int j = i * i; j <= nMax; j += i ) bit[j] = 0;
        } 
    }
    for ( int i = 0; i < nMax; i++ ) 
        if ( bit[i] )
            primes.push_back(i);
}
void segSeive(ll l, ll r){bool isPrime[r-l+1];for ( int i = 0; i < r-l+1; i++ )isPrime[i] = true;if ( l == 1 ) isPrime[0] = false;for ( int i = 0; primes[i]*primes[i] <= r; i++ ){int currentPrime = primes[i];ll base = (l/currentPrime)*currentPrime;if ( base < l )base += currentPrime;for ( ll j = base; j <= r; j+= currentPrime ){isPrime[j-l] = false;}if ( base == currentPrime ) isPrime[base-l] = true;} /* for ( int i = 0; i < r - l + 1; i++ )if ( isPrime[i] )cout << i+l << endl; */}

// class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;


// int n, s;
// const int N = 1e5+5;
// vector<ll> adj[N];
// queue<int> q;
// vector<bool> used(n);
// vector<int> d(n), p(n);


// int bfs(int src, int des ){
    
//     q.push(s);
//     used[s] = true;
//     p[s] = -1;
//     while (!q.empty()) {
//         int v = q.front();
//         q.pop();
//         for (int u : adj[v]) {
//             if (!used[u]) {
//                 used[u] = true;
//                 q.push(u);
//                 d[u] = d[v] + 1;
//                 p[u] = v;
//             }
//         }
//     }

//     // shortest path
//     /* if (!used[u]) {
//         cout << "No path!";
//     } else {
//         vector<int> path;
//         for (int v = u; v != -1; v = p[v])
//             path.push_back(v);
//         reverse(path.begin(), path.end());
//         cout << "Path: ";
//         for (int v : path)
//             cout << v << " ";
//     } */
// }


