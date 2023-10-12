// https://codeforces.com/contest/166/problem/B

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
// 1 upper bound lower bound multimap 
// 2 two pointer
// 3 set
// 4 sieve
// 5 min heap max heap

struct dot{ long long x, y; } a[101000], b;

ll cross ( dot d1, dot d2, dot d3 ){
    return ( d2.x-d1.x )*(d3.y-d1.y ) - ( d3.x-d1.x) * (d2.y-d1.y);
}

void solve(){
    ll n,i,m,ans =0;
    cin >> n;
	REP(i,n) cin >> a[i].x >> a[i].y;
	cin >> m;
	REP(i,m)
	{
		cin >> b.x >> b.y;
		int l=1,r=n-1,mid,res=1;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (cross(a[0],b,a[mid])>0)
				l=mid+1;
			else
				res=mid,r=mid-1;
		}
		if (res==1 || cross(a[0],b,a[n-1])==0) continue;
		if (cross(a[res],b,a[res-1])<0) ++ans;
	}
	if (ans==m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
    
        
}
    
    
    


signed main(){
    io;
    ll tt = 1;
    // cin >> tt;    
    while ( tt-- )  solve();
}