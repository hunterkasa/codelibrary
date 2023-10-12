#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int lcs( string &x, string &y, int n, int m ){
    if ( m == 0 || n == 0 ) return 0;

    if ( dp[n][m] != -1 )
        return dp[n][m];

    if ( x[n] == y[m] )
        return dp[n-1][m-1] = 1+lcs(x,y,n-1,m-1);
    
    return dp[n-1][m-1] = max( lcs( x,y,n-1,m ), lcs(x,y,n,m-1) ); 
}

int main(){
    memset(dp,-1,sizeof(dp));

    string x = "AGGTAB";
    string y = "GXTXAYB";
    int n = x.size();
    int m = y.size();

    cout << lcs(x,y,n,m);

}