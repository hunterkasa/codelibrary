#include <iostream>
using namespace std;
 
void merge(int arr[], int l, int m, int r){
    int nL = m - l + 1;
    int nR = r - m;
 
    int L[nL], R[nR];
 
    for (int i = 0; i < nL; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < nR; j++)
        R[j] = arr[m + 1 + j];
 
 
    int i = 0, j = 0;
    int k = l;
 
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < nL) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < nR) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[],int l,int r){
    if(l >= r)
        return;

    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 
void printArray(int A[], int size){
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
 
int main(){
    
    // int n;  cin >> n;
    // int arr[n];
    // for ( int i = 0; i < n; i++ )
    //     cin >> arr[i];
    int arr[5] = {5,4,3,2,1}, n = 5; 
    
    
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

}