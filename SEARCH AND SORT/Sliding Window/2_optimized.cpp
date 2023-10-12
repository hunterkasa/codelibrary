// Remocve all the repetitive work
// Time complexity O(N)

#include <bits/stdc++.h>
#include <array>
using namespace std;

// int main(){
//     array<int,5> arr{ 1, 2, 3, 4, 5 };
//     int i , j , m;
//     m = 3;
//     int maxSum = arr[0]+arr[1]+arr[2];
//     for ( i = 3; i < arr.size(); i++ ){
//         int temp;
//         temp = maxSum + arr[i] - arr[i-3] ;
//         maxSum = max(maxSum, temp);
//     }
//     cout << maxSum << endl;
// }


// GeeksForGeek

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
    // n must be greater
    if (n < k) {
        cout << "Invalid";
        return -1;
    }
  
    // Compute sum of first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];
  
    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }
  
    return max_sum;
}
  
// Driver code
int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}