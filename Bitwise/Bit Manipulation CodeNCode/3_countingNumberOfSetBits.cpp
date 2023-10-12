#include <iostream>
using namespace std;

// simple approach
// int main(){
//     int q,n,i;
//     cin >> q;
//     while ( q-- ){
//         cin >> n;
        
//         int cnt = 0;
//         while ( n > 0 ){
//             if ( (n & 1) > 0 ){
//                 cnt++;
//             }
//             n = n >> 1; 
//         }
//         cout << cnt << endl;
//     }
// }

// after observing :- 
int main(){
    int q,n,i;
    cin >> q;
    while ( q-- ){
        cin >> n;
        
        int cnt = 0; 
        while ( n > 0 ){
            cnt++;
            n = n & (n - 1);
        }
        cout << cnt << endl;
    }
}