#include <iostream>
using namespace std;

int main(){
    int t;  cin >> t;
    long long int a , b;
    while ( t-- ){
        cin >> a >> b;
        long long int d = b - a;
        long long int res = 0; 
        long long int f = 1;
        
        for ( int i = 0; i < 32; i++ ){
            if ( d > ( f << i) ) continue;
            else 
                if ( (a & ( f << i )) && (b & ( f << i )))
                    res += f << i;
        }
        cout << res << endl;
    }
}