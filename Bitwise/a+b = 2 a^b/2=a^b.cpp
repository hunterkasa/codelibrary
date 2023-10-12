#include <bits/stdc++.h>
using namespace std;
 
#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl            "\n"
#define fr1( i, a, n )  for( long long i = a; i < n; i++ )
#define fr( i, n )      for( long long i = 0; i < n; i++ )
#define rf( i, n )      for( long long i = n-1; i >= 0; i-- )
#define py              cout << "YES\n";
#define pyy             cout << "Yes\n";
#define pn              cout << "NO\n";
#define pnn             cout << "No\n";
#define all(v)          v.begin(),v.end()
#define pb              push_back
#define vll             vector<long long>
#define mll             map<long long,long long>
#define vpll            vector<pair<long long,long long>>
#define lb(v,x)         lower_bound(all(v),x)-v.begin()
#define ub(v,x)         upper_bound(all(v),x)-v.begin()
#define precision(a)    cout << fixed << setprecision(a) 
#define mem(x,y)        memset(x,y,sizeof(x))
#define pll             pair<ll,ll>
#define sr(a)           sort(all(a))
#define srg(a)          sort(all(a),greater<>())
#define re              return;

// #define int long long
typedef long long ll;

void fast(){
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /*freopen("output.txt","w",stdout);*/
    #endif
}


void findNums(int X, int Y)
{
 
    // Initialize the two numbers
    int A, B;
 
    // Case 1: X < Y
    if (X < Y) {
        A = -1;
        B = -1;
    }
 
    // Case 2: X-Y is odd
    else if (abs(X - Y) & 1) {
        A = -1;
        B = -1;
    }
 
    // Case 3: If both Sum and XOR
    // are equal
    else if (X == Y) {
        A = 0;
        B = Y;
    }
 
    // Case 4: If above cases fails
    else {
 
        // Update the value of A
        A = (X - Y) / 2;
 
        // Check if A & Y value is 0
        if ((A & Y) == 0) {
 
            // If true, update B
            B = (A + Y);
        }
 
        // Otherwise assign -1 to A,
        // -1 to B
        else {
            A = -1;
            B = -1;
        }
    }
    
    if ( A == -1 ){
        cout << -1; 
        re
    }
    // Print the numbers A and B
    cout << A << " " << B;
}

void solve(){
 
    // ll n;   cin >> n;
    // vll a(n);   for ( int i = 0; i < n; i++ )  cin >> a[i];
    
    ll n;   cin >> n;
    
    findNums(2*n,n);
    cout << endl;


}

    
signed main(){
    class Timer { private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now();cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;
    // fast(); 
    ll tt = 1;
    cin >> tt;
    ll i = 1;
    while ( tt-- > 0 ){
        // cout << "Case " << i++ << ": ";
        solve();
    }      
    return 0;
}    