#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define REP( i, n )     for( long long i = 0; i < n; i++ )
#define py              cout << "YES\n";
#define pn              cout << "NO\n";
#define all(v)          v.begin(),v.end()

typedef long long ll;
const int MOD = 1e9 + 7;

bool search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}

//  THREE SUM PROBLEM!!!

void solve(){
    ll n;   cin >> n;
    int target; cin >> target;
    vector<ll> a(n);
    for(auto &e : a )   cin >> e;
    bool found = false;
    sort(all(a));
    for ( int i = 0; i < n; i++ ){
        int low = i + 1, hi = n-1;
        while ( low < hi ){
            int current = a[i] + a[low] + a[hi];
            if ( current == target ){
                found = true;
                break;
            }
            if ( current < target ){
                low++;
            }
            else {
                hi--;
            }
        }
    }
    if ( found ){
        py;
    } else {
        pn;
    }
    
}

signed main(){
    io;
    ll tt = 1;
    // cin >> tt;    
    while ( tt-- )  solve();
}