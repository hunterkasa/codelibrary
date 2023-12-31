#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vmi;
typedef vector<pi> vpi;
typedef vector<vpi> vmpi;

const int INF = 1e9 + 19;

int n, m;   
vmpi G;
vb mark;
vi dist;

void spfa(int s)
{
    fill(dist.begin(), dist.end(), INF);
    fill(mark.begin(), mark.end(), false);
    
    mark[s] = true;
    dist[s] = 0; 
    
    deque<int> S(1, s);
    while (!S.empty())
    {
        int u = S.front();
        S.pop_front();
        mark[u] = false;
        
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i].fi;
            int w = G[u][i].se;

            if (dist[v] > dist[u] + w) 
                dist[v] = dist[u] + w;  

            if (!mark[v]) 
            {
                S.push_back(v);
                mark[v] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    G.resize(n + 1);
    mark.assign(n + 1, false);
    dist.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        G[u].pb({v, c});
    }

    int s, t;
    cin >> s >> t;

    spfa(s);
    if (dist[t] == INF)
        cout << "There is no path from " << s << " to " << t;
    else 
        cout << "Min distance(" << s << " -> " << t << ") = " << dist[t];
        
    return 0;
}