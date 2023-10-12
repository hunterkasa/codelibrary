#include <bits/stdc++.h>
using namespace std;
 
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F( i, n ) for( int i = 0; i < n; i++ )
#define ll long long
#define endl '\n'
#define pb push_back
#define ppb pop_back

// ll solve(ll n, ll m){
    
// }

bool isPalindrome( ll n ){
    string s = to_string(n);
    ll left = 0, right = s.length() - 1;
    while ( left < right ){
        if ( s[left] != s[right])   return false;
        left++;
        right--;
    }
    return true;
    
}

signed main(){

    io;
    
    ll largest = 0;
    for ( ll i = 1; i < 999; i++ ){
        for ( ll j = 1; j < 999; j++ ){
            ll num = i * j;
            if ( num > largest && isPalindrome(num) ){
                largest = i*j;
            }
        }
    }
    
    cout << largest << endl;
}
