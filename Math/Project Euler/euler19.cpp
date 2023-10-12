#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <queue>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

#define io              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define REP( i, n )     for( long long i = 0; i < n; i++ )
#define FOR( i, a, b )  for( long long i = a; i <= b; i++ )
#define endl            '\n'
#define pb              push_back
#define ppb             pop_back
#define ANS(x)          cout << x << endl;
#define MAX             INT_MIN
#define MIN             INT_MAX
#define INF             1000000007
#define all(v)          v.begin(),v.end()
#define rall(v)         v.rbegin(),v.rend()
#define ff              first
#define ss              second
#define READ(x)         freopen(x,"r",stdin)
#define WRITE(x)        freopen(x,"w",stdout)
#define poy             cout << "YES\n";
#define pon             cout << "NO\n";
 
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef vector<string>vs;
typedef long long int lli;
typedef vector<long long> vll;
typedef vector<pair<int , int>> pi;
typedef vector<pair<long , long>> pll;

const int MOD = 1e9 + 7;

// ll n, m, k, a, b, c, d, x, y, z, w, i, j, l, ans = 0, res = 0;
// string s;


void solve(){
    
    // map < string, int > mp;
    
    // mp.insert(pair<string,int>("January", 31));
    // mp.insert(pair<string,int>("February", 28));
    // mp.insert(pair<string,int>("March", 31));
    // mp.insert(pair<string,int>("April", 30));
    // mp.insert(pair<string,int>("May", 31));
    // mp.insert(pair<string,int>("June", 30));
    // mp.insert(pair<string,int>("July", 31));
    // mp.insert(pair<string,int>("August", 31));
    // mp.insert(pair<string,int>("September", 30));
    // mp.insert(pair<string,int>("October", 31));
    // mp.insert(pair<string,int>("November", 30));
    // mp.insert(pair<string,int>("December", 31));
    
    // int day = 1;
    // int sunC = 0;
    
    // map < string, int >::iterator itr;
    // for ( int i = 1901; i <= 2000; i++ ){
    //     for ( itr = mp.begin(); itr != mp.end(); itr++ ){
    //         day += itr->second;
    //         if ( i % 4 == 0 && itr->first == "February" ){
    //             day += 1;
    //         }
    //         if ( day % 7 == 0 ){
    //             sunC += 1;
    //         }
    //     }
    // }
    
    // cout << sunC << endl;
    int k = 0;
    // String months[] = { "January", "February", "March", "April", "May", "June",
    // "July", "August", "September",
    // "October", "November", "December" };
    string Days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int MonthsDdays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int counter = 0;
    for (int t = 1900; t <= 2000; t++) {
        MonthsDdays[1]=28;
        if (t % 4 == 0) {
            if (t % 100 == 0)

            {
                if (t % 400 == 0)
                    MonthsDdays[1] = 29;
            } else if (t % 100 != 0)
                MonthsDdays[1] = 29;

        }

        int p = 0;
        while (p < 12) {

            for (int j = 0; j < MonthsDdays[p]; k++, j++) {
                if (k == 7)
                    k = 0;
                if (Days[k] == ("Sunday") && j == 0 && t > 1900) {
                    counter++;

                }
            }
            p++;
        }
    }
    cout << counter << endl;;
}

signed main(){
    
    io;
    // #ifndef ONLINE_JUDGE
    //     READ("a.txt");
    //     WRITE("a.txt");
    // #endif
    ll t = 1;
    // cin >> t;    
    while ( t-- ){
        solve();
    }
}