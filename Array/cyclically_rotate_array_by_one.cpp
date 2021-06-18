#include<iostream>
#include<stdlib.h>

using namespace std;

void rotate_cyclically(int Arr[], int N)
{
    int temp,i;
    temp=Arr[N-1];
    for(i=N-1;i>0;i--)
    Arr[i]=Arr[i-1];
    Arr[i]=temp;
}

void printarray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    cout<<arr[i]<<' ';
}

int main()
{
    system("cls");
    int N;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>N;
    int Arr[N];
    cout<<"\n Enter the elememts of array: ";
    for(int i=0;i<N;i++)
    cin>>Arr[i];
    rotate_cyclically(Arr,N);
    cout<<"\n Cyclically Rotated array is: ";
    printarray(Arr,N);
    return 0;
}