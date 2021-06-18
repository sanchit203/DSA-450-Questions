#include<bits/stdc++.h>

using namespace std;

void Rearrange(int A[], int n)
{
    sort(A,A+n);
    int i,j,k,temp;
    for(i=0;A[i]<0;i++);
    for(j=1,k=i;j<=i&&k<n;k++,j=j+2)
    {
        if(A[j]>0)
        break;
        temp=A[j];
        A[j]=A[k];
        A[k]=temp;
    }
    return;
}

void printarray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    cout<<arr[i]<<' ';
}
int main()
{
    system("cls");
    int n;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>n;
    int arr[n];
    cout<<"\n Enter the elements of array: ";
    for(int i=0; i<n; i++)
    cin>>arr[i];
    Rearrange(arr,n);
    cout<<"\n Rearranged array is: ";
    printarray(arr,n);
    return 0;
}