#include<iostream>
using namespace std;
void Merge(int *L, int *R, int *A, int nL, int nR)
{
    int i=0,j=0,k=0;
    while(i<nL && j<nR)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<nL)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<nR)
    {
        A[k]=R[j];
        j++;
        k++;
    }


}
void MergeSort(int *A, int n)
{
    if(n<2)
    {
        return;
    }
    int mid=(n/2);
    int nL=mid;
    int nR=n-mid;
    int L[nL];
    int R[nR];

    for(int i=0;i<mid+1;i++)
    {
        L[i]=A[i];
    }
    for(int i= mid;i<n;i++)
    {
        R[i-mid]=A[i];
    }
    MergeSort(L, nL);
    MergeSort(R,nR);
    Merge(L,R,A,nL,nR);
}

void show(int *A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
  int A[5]={5,4,3,2,1};
  show(A, 5);
  MergeSort(A,5);
  show(A, 5);
}
