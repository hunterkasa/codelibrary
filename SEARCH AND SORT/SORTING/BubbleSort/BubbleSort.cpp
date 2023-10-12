#include<iostream>
using namespace std;

void swap( int array[], int i, int j ){
    
    if ( i == j ){
        return;
    }
    
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr, j, j+1);
    // CLASS
    /* bool swapped = true;
    while ( swapped ){
        swapped = false;
        for ( int i = 1; i < n; i++ ){
            if ( arr[i-1] > arr[i] ){
                swap(arr[i-1], arr[i]);
                swapped = true;
            }
        }
    } */
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main(){
    
    int n; cin >> n;
    int intArray[n];
    
    for ( auto &e : intArray )    cin >> e;
    
    bubbleSort(intArray, n);
    printArray(intArray, n);
}