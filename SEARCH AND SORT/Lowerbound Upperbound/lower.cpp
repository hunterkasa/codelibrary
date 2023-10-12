#include <bits/stdc++.h>
using namespace std;

// if such element exists returns that element  
// else returns the next bigger element
int lower_bound( vector<int> &v, int element ){
    int lo = 0, hi = v.size()-1;
    int mid;
    while ( hi - lo > 1 ){
        int mid = ( hi+lo )/ 2;
        if ( v[mid] < element ){
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    if ( v[lo] >= element ){
        return lo;
    }
    if ( v[hi] >= element ){
        return hi;
    }
    return -1;
}

int main(){
    int n;  cin >> n;
    vector<int> v(n);
    for ( auto &e: v )  cin >> e;
    
    sort(v.begin(), v.end());
    
    int element;    cin >> element;
    
    int lb = lower_bound( v, element );
    cout << lb << " " << ( lb != -1 ? v[lb] : -1 ) << endl;
}