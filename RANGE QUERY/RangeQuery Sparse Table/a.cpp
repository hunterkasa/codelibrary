#include<iostream>
using namespace std;

int const nmax = 200000;
int const lgmax = 20;
int v[5 + nmax];
int rmq[1 + lgmax][5 + nmax];
 
int lg(int number) {
    return 31 - __builtin_clz(number);
}
 
void precompute(int n) {
    for(int i = 1;i <= n; i++)
        rmq[0][i] = v[i];
    for(int h = 1; h <= lgmax; h++)
        for(int i = 1;i <= n - (1 << h) + 1; i++)
        rmq[h][i] = min(rmq[h - 1][i], rmq[h - 1][i + (1 << (h - 1))]);
}
 
int extract(int x, int y) {
    int h = lg(y - x + 1);
    return min(rmq[h][x], rmq[h][y - (1 << h) + 1]);
}

void solve(){
    
    long long n, q;    cin >> n >> q;
    for ( int i = 1; i <= n; i ++ ){
        cin >> v[i];
    }
    precompute(n);
    
    while (q--){
        long long x, y;
        cin >> x >> y;
        cout << extract(x,y) << endl;
    }
        
    
    
}
    