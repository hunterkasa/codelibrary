#include <bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define REP( i, n )  for( long long i = 1; i <= n; i++ )
#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define f( n )          for( long long i = 0; i < n; i++ )
#define rf( i, n )      for( long long i = n; i >= 0; i-- )
#define py              cout << "YES\n";
#define pyy             cout << "Yes\n";
#define pyyy            cout << "yes\n";
#define pn              cout << "NO\n";
#define pnn             cout << "No\n";
#define pnnn            cout << "no\n";
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
#define mem(x)        memset(x,0,sizeof(x))
// #define INF             INT_MAX;
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

int n,m;
const int N = 1e5+5;
vll a1[N], a[N], a2[N];
ll vis[N], vis1[N], vis2[N];
vll ans;
ll indeg[N];

void topo_dfsa(int x){
    vis[x] = 1;
    for ( int node : a[x] ){
        if ( !vis[node] )
            topo_dfsa(node);
    }
    ans.pb(x);
}
void topo_dfsa1(int x){
    vis1[x] = 1;
    for ( int node : a1[x] ){
        if ( !vis1[node] )
            topo_dfsa1(node);
    }
    ans.pb(x);
}
void topo_dfsa2(int x){
    vis2[x] = 1;
    for ( int node : a2[x] ){
        if ( !vis2[node] )
            topo_dfsa2(node);
    }
    ans.pb(x);
}


void dfsa(int x){
    vis[x] = 1;
    for ( int node : a[x] ){
        if ( !vis[node] )
            dfsa(node);
    }
}
void dfsa1(int x){
    vis1[x] = 1;
    for ( int node : a1[x] ){
        if ( !vis1[node] )
            dfsa1(node);
    }
}
void dfsa2(int x){
    vis2[x] = 1;
    for ( int node : a2[x] ){
        if ( !vis2[node] )
            dfsa2(node);
    }
}

ll parent[N];
ll dist[N];
void bfs( int s ){
    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : a[v]) {
            if (!vis[u]) {
                vis[u] = true;
                parent[u] = v;
                q.push(u);
            } else if ( dist[u] < dist[v]+1 ){
                dist[u] = dist[v] + 1;
                parent[u] = v;
            } 
        }
    }
}

void solve(){
    
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];
    
    
    cout << gcd(3,gcd(6,gcd(4,gcd(6,2))));
    
    
}
    
    
signed main(){
    fast(); 
    class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    ll tt = 1;
    // cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        solve();
    }      
}  