#include <bits/stdc++.h>
using namespace std;
 
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP( i, n ) for( int i = 0; i < n; i++ )
#define ll long long
#define endl '\n'
#define pb push_back
#define ppb pop_back

int solve(int m){
    
    int sum = 0;
    int a = 1;
    int b = 2;
    
    if ( m >= 2 ){
        sum += b;
    }
    
    int c;
    while ( c <= m ){
        c = a + b;
        if ( c % 2 == 0 ) {
            sum += c;
        }
        
        a = b;
        b = c;
    }
    return sum;
}

signed main(){

    io;
    
    int n = 4e6;
    cout << solve(n) << endl;
    
    
}