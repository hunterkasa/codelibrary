#include <iostream>
using namespace std;

int main(){
    int q,n,i;
    cin >> q;
    while ( q-- ){
        cin >> n >> i;
        
        int f = 1;
        f = f << i;
        
        int res = n & f;
        if ( res == 0 ) cout << "false" << endl;
        else cout << "true" << endl;
    }
}