// https://www.youtube.com/watch?v=zEAmQqOpfzM&t=1270s&ab_channel=Luv
// O(alpha(n)) // reverse akerman function
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int parent[N];
int Size[N];

void make(int v){
    parent[v] = v;
    Size[v] = 1;
}

int find( int v ){
    if ( v == parent[v] )   return v;
    return parent[v] = find(parent[v]);
}

void Union( int a, int b ){
    a = find(a);
    b = find(b);

    if ( a != b ){
        if ( Size[a] < Size[b] )    
            swap(a,b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main(){

}