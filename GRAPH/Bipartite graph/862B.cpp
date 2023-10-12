// https://codeforces.com/contest/862/problem/B
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

const int N = 2e5;
int n;
vll g[N];
ll color[N];
ll vis[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    color[src] = 1;

    while ( !q.empty() ){
        int x = q.front(); q.pop();

        for ( auto child : g[x] ){
            if ( !vis[child] ){
                vis[child] = 1;
                q.push(child);
                color[child] = (color[x] ^ 1);
            }
        }
    }

}

void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];

    cin >> n;
    fr(i,n-1){
        int x,y;    cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    bfs(1);
    
    ll ans1 = 0, ans2 = 0;
    for ( int i = 1; i <= n; i++ ){
        if ( color[i] == 0 )
            ans1++;
        else ans2++;
    }
    
    cout << ans1*ans2 - ( n-1 ) << endl;    

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