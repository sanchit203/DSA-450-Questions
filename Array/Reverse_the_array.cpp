#include<iostream>
#include<stdlib.h>

using namespace std;

void Rev_array(int arr[], int n)
{
    int i,j,temp;
    for(i=0,j=n-1; i<j; i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
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
    Rev_array(arr,n);
    cout<<"\n Reversed array is: ";
    printarray(arr,n);
    return 0;
}