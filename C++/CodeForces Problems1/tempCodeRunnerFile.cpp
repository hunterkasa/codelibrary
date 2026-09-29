#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include "template.cpp"
#else
    #define debug(...)
    #define debugArr(a, n)
#endif

#define io ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define endl '\n'

void Wah() {
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        // freopen("output.txt","w",stdout);
    #endif
}

typedef vector<long long> vll;
typedef long double ld;
#define int long long
#define ll long long
typedef pair<int,int> pii;





void senritsu() {

    int n, m, k; cin >> n >> m >> k;
    int x, y; cin >> x >> y;
    int a[n]; for ( int i = 0; i < n; i++ ) cin >> a[i];
    int b[m]; for ( int j = 0; j < m; j++ ) cin >> b[j];

    sort(a,a+n);
    sort(b,b+m);

    int pre[n]{};
    for ( int i = 0; i < n; i++ ){
        pre[i] = a[i];
        if ( i ) pre[i] += pre[i-1];
    }

    int ans = 0;
    int one = x, two = y;
    for ( int i = 0; i < m; i++ ){
        if ( two * k < b[i] ) break;
        int rem = ( b[i] + k - 1 ) / k;
        two -= rem;
        one += rem * k - b[i];
        int cnt = upper_bound(pre,pre+n,one+two*k) - pre;
        ans = max( ans, cnt + i + 1 );
    }
    cout << ans << endl;

}

signed main() {
    // 君は分かってるかな 教えてくれた 戻らないその幸せは
    Wah();
    int tt = 1;
    // cin >> tt;
    while ( tt-- > 0 ) {
        senritsu();
    }
    return 0;
}