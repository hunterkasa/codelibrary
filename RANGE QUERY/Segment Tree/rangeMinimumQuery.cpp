#include <bits/stdc++.h>
#include <valarray>
using namespace std;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define REP( i, a, n )  for( long long i = a; i <= n; i++ )
#define py              cout << "YES\n";
#define pyy             cout << "Yes\n";
#define pn              cout << "NO\n";
#define pnn             cout << "No\n";
#define all(v)          v.begin(),v.end()
#define rall(v)         v.rbegin(),v.rend()
#define pb              push_back
#define vll             vector<ll>
#define val             valarray<ll> 
#define itn             int
#define int             ll

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

bool search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}
ull gcd( ull a, ull b ){
    if ( b == 0 )    return a;
    return gcd(b,a%b);
}
ull lcm( ull a, ull b){
    return a/gcd(a,b)*b;
}

ll fact( ll a, ll b, ll c ){
    if ( b == 0 )
        return 1;
    
    if ( b % 2 == 0 ){
        ll x = fact( a, b/2, c );
        return (x*x)%c;
    } else 
        return a % c * fact(a,b-1,c) % c;
}
// vll input[2000001], segtree[20000001][20000001];
// void constructTree( vll input[], vll segTree[], int low, int high, int pos){
//     if ( low == high ){
//         segTree[pos] = input[low];
//         return;
//     }
//     int mid = (low+high)/2;
//     constructTree(input,segTree,low,mid,2*pos+1);
//     constructTree(input,segTree,mid+1,high,2*pos+2);
//     segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
// }

const int N = 200001;
int ar[N];
int st[4*N];
 
int build(int si , int ss , int se)
{
	if(ss == se) return st[si] = ar[ss];
	
	int mid = (ss + se) >> 1;
	
	return st[si] = min(build(2*si , ss , mid) , build(2*si+1 , mid+1 , se));
}
 
int getMin(int si , int ss , int se , int l , int r)
{
	if(l > se || r < ss) return 2000000000;
	
	if(ss >= l && se <= r) return st[si];
	
	int mid = (ss + se) >> 1;
	return min(getMin(2*si , ss , mid , l , r) , getMin(2*si+1 , mid+1 , se , l , r));
}

void solve(){
    // cout << "==================\n";
    // ll n,x;   cin >> n >> x;
    // vector<ll> a(n),b(n+1); 
    // for ( auto &e: a )  cin >> e;
    
    
	int n , q , a , b;
	cin>>n>>q;
	
	REP(i, 1 , n) cin>>ar[i];
	
	build(1 , 1 , n);
	while(q--)
	{
		cin>>a>>b;
		cout<<getMin(1 , 1 , n , a , b)<<endl;
	}
    
    
}
    
    
     


signed main(){
    io;
    ll tt = 1;
    // cin >> tt;    
    ll i = 1;
    while ( tt-- ){
    // cout << "Case " << i++ << ":\n";    
    solve();
    }        
        
}