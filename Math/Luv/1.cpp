// https://www.youtube.com/watch?v=RCq5TYMZEwg&list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV
// Why Print answer modulo 10^9+7 | Modular Arithmetic

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    
    long long fact = 1;
    long long m = 47;
    // multiply
    for ( int i  = 2; i <= n; i++ ){
        fact = ((fact%m)*(i%m))%m;
    }
    cout << fact << endl;
    
    fact = 1;
    // summation 
    for ( int i = 2; i <= n; i++ ){
        fact = (fact % m + i % m) % m;
    }
    cout << fact << endl;
    
    fact = 1;
    // substraction
    for ( int i = 2; i <= n; i++ ){
        fact = (((fact%m) - (i%m) + m) % m);
    }
    cout << fact << endl;
}