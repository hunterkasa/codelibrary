// https://www.youtube.com/watch?v=0XYSdIVY6Ks
#include<iostream>
using namespace std;

const int n = 4;
int edges[n][n];

void print( int n, int sv, bool* visited){
    cout << sv << endl;
    for ( int i = 0; i < n; i++ ){
        if ( i == sv )
            continue;
        if ( edges[sv][i] == 1 ){
            if( visited[i] )    
                continue;
            print(  n, i, visited );
        }
    }
}

int main(){
    int e;    cin >> e;
    
    
    
    for ( int i = 0; i < e; i++ ){
        int f,s;    cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    bool visited[n] = {0};
    
    print(n,0,visited);
}