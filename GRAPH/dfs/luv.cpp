#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5+10;

vector<int> g[N];

bool vis[N];

void dfs( int vertex ){
    // Take action on vertex after 
    // entering the vertex
    cout << vertex << endl;
    if(vis[vertex])  
        return;
        
    vis[vertex] = true;
    for ( int child : g[vertex] ){
        cout << "Parent " << vertex << ", child " << child << endl;
        // Take action on child before 
        // entering the child node
        dfs(child);
        // Take action on child after 
        // exiting child node
    }
    // Take action on vertex before 
    // exiting the vertex
}

int main(){
    int n,m;    
    cin >> n >> m;
    
    for ( int i = 0; i < n; i++ ){
        int x,y;    
        g[x].push_back(y);
        g[y].push_back(x);
    }
}