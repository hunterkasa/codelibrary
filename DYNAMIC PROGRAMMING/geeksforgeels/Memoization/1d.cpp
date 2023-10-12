#include<bits/stdc++.h>
using namespace std;

int dp[100000];

int fib(int n){
    if ( n <= 1 )
        return n;
    
    if ( dp[n] != -1 )
        return dp[n];
    
    return dp[n] = fib(n-1) + fib(n-2);
}

int main(){
    int n = 1000;
    for ( int i = 0; i < n; i++ ){
        dp[i] = -1;
    }

    cout << fib(10) << endl;
}