#include <iostream>
using namespace std;

int main(){
    int q,n,i;
    cin >> q;
    while ( q-- ){
        cin >> n >> i;
        
        // cout << n << " << " << i << " = " << (n << i) << endl; // left shift
        cout << n << " >> " << i << " = " << (n >> i) << endl; // right shift
    }
}