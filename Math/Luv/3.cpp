// https://www.youtube.com/watch?v=yEa0vkjJSf0&list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV&index=4
// PLAYING WITH BITS | Set, Unset, Count Bits

#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for( int i = 10; i >= 0; i-- ){
        cout << ( (num >> i ) & 1 );
    }
    cout << endl;
}

int main(){
    printBinary(9);
    int a = 9;
    int i = 3;
    
    if ( (a & (1 << i)) != 0 ){
        cout << "set bit" << endl;
    } else {
        cout << "not set bit" << endl;
    }
    
    // bit set
    a = a | (1<<1);
    printBinary(a);
    
    // unset bit 
    a = a ^ (1<<1);
    printBinary(a);
    
    printBinary(~a); // inverses a binary number
    
}