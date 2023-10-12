#include<bits/stdc++.h>
using namespace std;

int dp[100000];

unsigned long int binomialCoeff(unsigned int n,unsigned int k){
    unsigned long int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int catalan( int n ){
    
    int c = binomialCoeff(2*n,n);

    return dp[n] = c/(n+1);

}

int main(){
    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";
}