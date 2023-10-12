#include<bits/stdc++.h>
using namespace std;


int dp[100][100][100];

int lcs( string &x, string &y, string &z, int n, int m, int o ){
    if ( m == 0 || n == 0 || o == 0 )   return 0;

    if ( dp[n-1][m-1][o-1] != -1 )    return dp[n-1][m-1][o-1];

    if ( x[n-1] == y[m-1] && y[m-1] == z[o-1] )
        return dp[n-1][m-1][o-1] = 1 + lcs(x,y,z,n-1,m-1,o-1);
    return dp[n-1][m-1][o-1] = max( {lcs(x,y,z,n-1,m,o), lcs(x,y,z,n,m-1,o), lcs(x,y,z,n,m,o-1)} );

}

int main(){
    memset(dp,-1,sizeof(dp));
    string x = "geeks";
    string y = "geeksfor";
    string z = "geeksforgeeks";

    int n = x.size();
    int m = y.size();
    int o = z.size();

    cout << lcs(x,y,z,n,m,o);
}