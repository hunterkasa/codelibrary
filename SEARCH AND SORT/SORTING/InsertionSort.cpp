#include <iostream>
using namespace std;

void printArray( int arr[], int n ){
    for ( int i = 0; i < n; i++ ){
        cout << arr[i] << " ";
    }   cout << endl;
}

void incertionSort ( int arr[], int n ){
    int key; 
    int j = 0;
    for ( int i = 1; i < n; i++ ){
        key = arr[i];
        j = i - 1;
        while ( j >= 0 && arr[j] > key ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        printArray(arr,n);
    }
} 

int main(){
    int n;  cin >> n;
    int arr[n];
    for ( int i = 0; i < n; i++ ){
        cin >> arr[i];
    }
    
    // printArray(arr, n);
    incertionSort(arr, n);
    // printArray(arr, n);
    
}