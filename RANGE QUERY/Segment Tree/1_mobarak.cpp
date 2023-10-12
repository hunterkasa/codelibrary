#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int arr[maxn], tree[4*maxn];

void build( int node, int l, int r ){
    if ( l == r ){
        tree[node] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node] = tree[node*2]+tree[node*2+1];
    // tree[node] = max(tree[node*2], tree[node*2+1]); 
}

int query( int node, int l, int r, /*query*/ int L, int R /*query*/ ){
    if ( l > R || r < L ){
        return 0; // for max use int min and min use max
    }

    if ( l >= L && r <= R ){
        return tree[node];
    }
    int mid = ( l + r )/ 2 ;
    int x = query( node*2, l, mid, L, R );
    int y = query( node*2+1, mid+1, r, L, R);
    return x + y;
}

void update( int node, int l, int r, int pos, int val ){
    if ( l == r ){
        tree[node] += val;
        return;
    }
    int mid = (l+r)/2;
    if ( pos <= mid ){
        update( node*2, l, mid, pos, val );
    } else {
        update( node*2+1, mid+1, r, pos, val );
    }
    tree[node] = tree[node*2]+tree[node*2+1]; 
} 

int main(){
    int n;  cin >> n;
    for ( int i = 1; i <= n; i ++ ){
        cin >> arr[i];
    }
    build(1,1,n);
    cout << query(1,1,n,2,5);
    update(1,1,n,3,2);
    cout << query(1,1,n,2,5);
}