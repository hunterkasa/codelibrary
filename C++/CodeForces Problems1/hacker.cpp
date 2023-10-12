#include <bits/stdc++.h>
using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define all(v)          v.begin(),v.end()
#define pb              push_back
#define vll             vector<long long>
#define mll             map<long long,long long>
#define vpll            vector<pair<long long,long long>>
#define precision(a)    cout << fixed << setprecision(a) 
#define sr(a)           sort(all(a))
#define srg(a)          sort(all(a),greater<>())

typedef long long ll;

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
    
    
    memset(vis,0,sizeof(vis));
    fr ( i, N ) a[i].clear();
    memset(col,0,sizeof(col));

    
    // getchar();
    cin >> n >> m;
    while(m--){
        int x,y;    cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }

    int mnc = 0, mnid= 0;
    fr ( i, n ){
        memset(col,0,sizeof(col));
        memset(vis,0,sizeof(vis));
        dfs(i,1);
        ll col1 = 0;
        fr ( i, n )
            if ( col[i] != 1 ) col1++;
        
        if ( mnc > col1 ){
            mnc = col1;
            mnid = i;
        }
    }    

    memset(col,0,sizeof(col));
    memset(vis,0,sizeof(vis));
    dfs(mnid,1);
    int col1 = 0;
    vll ans;
    fr ( i, n )
        if ( col[i] != 1 ) col1++, ans.pb(i);

    
    cout << col1 << endl;
    for ( int i = 0; i < (int)ans.size(); i++ ){
        cout << ans[i];
        if ( i != (int)ans.size() - 1 )  cout << " ";
    }
    cout << endl;

}


int main(){
    io;
    ll tt = 1;
    cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        cout << "Case #" << i++ << ": ";
        solve();
    }      
    return 0;
}    