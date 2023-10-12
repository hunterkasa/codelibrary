#include<iostream>
using namespace std;

void swap( int arr[], int i, int j ){
    if ( i == j ){
        return;
    }
    
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    int arr[] = { 20, 35, -15, 7, 55, 1, -22 };
    int size = sizeof(arr)/ sizeof(arr[0]);
    
    for ( int last = size - 1; last > 0; last-- ){
        for ( int i = 0; i < last; i++ ){
            if ( arr[i] > arr[i+1] )
                swap( arr, i, i+1 );
        }
    }
    
    for ( int i = 0; i < size; i++ )
        cout << arr[i] << " ";
    
}