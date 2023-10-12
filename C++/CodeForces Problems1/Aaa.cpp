#include <bits/stdc++.h>
using namespace std;

int vis[5];
vector<int> b[5];
void dfs( int from ){
    vis[from] = 1;
    cout << from << ' ';
    for ( int child : b[from] ){
        if ( vis[child] == 0 ){
            dfs(child);
        }
    }
}

int main(){
    int n = 5;
    int a[5][5];

    a[0][1] = a[1][0] = a[2][1] = a[1][2] = 1; 

    b[0].push_back(1);
    b[1].push_back(0);
    b[1].push_back(2);
    b[2].push_back(1);

    dfs( 2 );


}