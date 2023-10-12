// Time complexity O(3*N)


#include <bits/stdc++.h>
#include <array>
using namespace std;

int main(){
    array<int,5> arr{ 1, 2, 3, 4, 5 };
    int i , j , m;
    m = 3;
    int maxSum = 0;
    for ( i = 0; i <= arr.size()-3; i++ ){
        int temp = 0;
        for ( int j = i; j < i+3; j++ )
            temp += arr[j];
        maxSum = max(maxSum, temp);
    }
    cout << maxSum << endl;
}