// https://vjudge.net/contest/530771?fbclid=IwAR2y04Y5rfAxO-vOIjzsTX7IBRX0xLsfkLww67hDsoS_pPq33AI3YY9H-M4#problem/G

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

const int maxn = 2e5+5;
int arr[maxn], tree[4*maxn];

void build( int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        tree[v] = 0;
    }
}
void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        tree[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
        tree[v] = tree[v*2]+tree[v*2+1]; 
    }
}
int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return tree[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return tree[v] + get(v*2, tl, tm, pos);
    else
        return tree[v] + get(v*2+1, tm+1, tr, pos);
}
void solve(){

    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    ll n, q;   cin >> n >> q;
    for ( int i = 1; i <= n; i++ ){
        cin >> arr[i];
    }
    build(1,1,n);
    while( q-- ){
        int k;  cin >> k;
        if ( k == 1 ){
            int ql, qr, x;
            cin >> ql >> qr >> x;
            update(1,1,n,ql,qr,x);
        } else {
            int x;  cin >> x;
            cout << get(1,1,n,x) << endl;
        }
    }
    
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