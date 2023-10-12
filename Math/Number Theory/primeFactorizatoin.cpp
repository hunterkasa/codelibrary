#include <bits\stdc++.h>
using namespace std;

#define ll long long


int main(){
    ll n;   cin >> n;
    
    vector<ll> primeFactors;
    
    for ( int i = 2; i * i <= n; i++ ){
        while( n % i == 0 ){
            primeFactors.push_back(i);
            n /= i;
        }
    }
    
    for ( auto & p : primeFactors ){
        cout << p << " ";
    }
    
}