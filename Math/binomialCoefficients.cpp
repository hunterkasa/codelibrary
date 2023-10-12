/*
    ( 5 )
            = 5!/ ((5-3)!*3!)
    ( 3 )
    
    n
      C     = n! / ((n-r)!*r!)
        r
        
*/

#include <iostream>
using namespace std;

// implementation:- 
/*
int fact( int a ){
    int factor = 1;
    for ( int i = 2; i <= a; i++ ){
        factor = factor*i;
    }
    return factor;
}

int main (){
    int n, r;   cin >> n >> r;
    int c = fact(n) / (fact(n-r)*fact(r));
    cout << c << endl;
}
*/

// recursive:- 
/*
int fact( int n, int k ){
    if ( k == 0 || k == n )
        return 1;
    
    return fact( n-1, k-1 ) + fact( n-1, k );
}

int main (){
    int n, r;   cin >> n >> r;
    int c = fact(n,r);
    cout << c << endl;
}
*/

// Dynamic programming:-
int C[10000][10000];

int fact( int n, int k ){
    int i , j;
    
    for ( i = 0; i <= n; i++ ){
        for ( j = 0; j <= min(i,k); j++ ){
            if ( j == 0 || j == i )
                C[i][j] = 1;
            else 
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}

int main (){
    int n, r;   cin >> n >> r;
    int c = fact(n,r);
    cout << c << endl;
}