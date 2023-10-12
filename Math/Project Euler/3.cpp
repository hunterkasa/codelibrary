#include <bits/stdc++.h>
using namespace std;
 
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F( i, n ) for( int i = 0; i < n; i++ )
#define ll long long
#define endl '\n'
#define pb push_back
#define ppb pop_back

ll solve(ll n){
    
    ll maxPF = -1;
    while ( n % 2 == 0 ){
        maxPF = 2;
        n /= 2;
    }
    
    for ( ll i = 3; i <= sqrt(n); i += 2 ){
        while ( n % i == 0 ){
            maxPF = i;
            n /= i;
        }
    }
    
    if ( n > 2 ) maxPF = n;
    return maxPF;
}

signed main(){

    io;
    
    ll n = 600851475143;
    cout << solve(n) << endl;
    
    
}