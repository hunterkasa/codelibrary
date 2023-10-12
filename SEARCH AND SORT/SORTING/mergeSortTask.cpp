/* Task: This code has a class named Point which contains two element x and y.
   The ar is array of Point class and has n = 100000 elements.
   You have to sort the ar array against it's y element.
   Like [(5, 3), (6, 1), (7, 2)] => [(6, 1), (7, 2), (5, 3)]
   if two Point's y is same, then compare using x.
   Like [(5, 3), (6, 1), (7, 1)] => [(6, 1), (7, 1), (5, 3)]

   First in the code, write your role in ROLL_NO variable
   and write your code in my_sort function.
   You can use any additional function as you like.
   DO NOT MODIFY ANY OTHER PART OF THE CODE

   The program will output smallest 10 element in the ar array.
   Like for roll 220121352, output will be

    Smallest 10 points are
    49734 14143
    49735 14143
    3764 31617
    3765 31617
    44726 32639
    44727 32639
    84844 37921
    84845 37921
    84196 42241
    84197 42241
    */


#include<iostream>
using namespace std;

const int n = 100000;

class Point {
public:
    int x,y;
};

void merge(Point arr[], int l, int m, int r){
    int nL = m - l + 1;
    int nR = r - m;

    Point L[nL], R[nR];

    for (int i = 0; i < nL; i++){
        L[i].x = arr[l + i].x;
        L[i].y = arr[l + i].y;
    }
    for (int j = 0; j < nR; j++){
        R[j].x = arr[m + 1 + j].x;
        R[j].y = arr[m + 1 + j].y;
    }


    int i = 0, j = 0;
    int k = l;

    while (i < nL && j < nR) {
        if (L[i].x <= R[j].x && L[i].y <= R[j].y) {
            arr[k].y = L[i].y;
            arr[k].x = L[i].x;
            i++;
        } else {
            arr[k].x = R[j].x;
            arr[k].y = R[j].y;
            j++;
        }
        k++;
    }

    while (i < nL) {
        arr[k].y = L[i].y;
        arr[k].x = L[i].x;
        i++;
        k++;
    }

    while (j < nR) {
        arr[k].x = R[j].x;
        arr[k].y = R[j].y;
        j++;
        k++;
    }
}
    
void my_sort(Point arr[],int l,int r) {
    // write your sort code here
    if(l >= r)
        return;

    int m = (l+r-1)/2;
    my_sort(arr,l,m);
    my_sort(arr,m+1,r);
    merge(arr,l,m,r);
}
 
 
 
// Write your role here
int ROLL_NO = 220121352;

int main() {
    Point ar[n+10];
    int i;
    int t = ROLL_NO - 100;
    for(i = 0; i < n+11; i++) {
        ar[i].x = i;
        ar[i].y = t ;
        if(i % 2 == 1) t = (t*2 + i)%ROLL_NO;
    }
    my_sort(ar, 0, n+11);
    cout<<"Smallest 10 points are"<<endl;
    for(i = 0; i < 10; i++) {
        cout<<ar[i].x << ' ' << ar[i].y << endl;
    }
    return 0;
}