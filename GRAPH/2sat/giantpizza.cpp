#include<bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl            "\n"
 
void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
}
 
typedef long long ll;
// #define int long long
 
  
struct two_sat {
    int n;
    vector<vector<int>> g, gr;
    vector<int> comp, topological_order, answer;
    vector<bool> vis;
 
    two_sat() {}
 
    two_sat(int _n) { init(_n); }
 
    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        answer.resize(2 * n);
    }
 
    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }
 
    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }
 
    // Only one of them is true
    void add_clause_xor(int i, bool f, int j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }
 
    // Both of them have the same value
    void add_clause_and(int i, bool f, int j, bool g) {
        add_clause_xor(i, !f, j, g);
    }
 
    void dfs(int u) {
        vis[u] = true;
 
        for (const auto &v : g[u])
            if (!vis[v]) dfs(v);
 
        topological_order.push_back(u);
    }
 
    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;
 
        for (const auto &v : gr[u])
            if (!vis[v]) scc(v, id);
    }
 
    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);
 
        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) dfs(i);
 
        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());
 
        int id = 0;
        for (const auto &v : topological_order)
            if (!vis[v]) scc(v, id++);
 
        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }
 
        return true;
    }
};
 
 
void tohka(){
 
    int m,n;
    cin >> m >> n;
 
    two_sat ts(n);
    for ( int i = 0; i < m; i++ ){
        int x, xx; 
        char c,cc;
 
        cin >> c >> x >> cc >> xx;
        bool na = (c == '+'),nb = (cc == '+');
        x--;
        xx--;
        
        ts.add_clause_or(x,na,xx,nb);
 
    }
 
    if ( ts.satisfiable() ){
        for ( int i = 0; i < n; i++ ) cout << (ts.answer[i] ? '+' : '-') << ' ';
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
 
}
 
signed main(){
    fast();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ){
        tohka();
    }      
    return 0;
}   