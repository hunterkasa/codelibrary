// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// #define ll long long int
// vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
//     vector<ll> ans;
//     vector<ll> vec;
//     ll i;
//     ll j = 0;
//     for ( i = 0; i < n; i++ ){
//         if ( a[i] < 0 )
//          vec.push_back(i);
//     }
    
//     int sz = vec.size();
//      for(i = 0; i <= n-k; i++){
//             if(j < sz && vec[j] >= i && vec[j] < i+k){
//                 ans.push_back(a[vec[j]]);
//                 if(i == vec[j])    j++;
//             }
//             else    ans.push_back(0);
//         }
//     return ans;

                                                 
// }