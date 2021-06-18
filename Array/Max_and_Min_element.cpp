#include<iostream>
#include<stdlib.h>

using namespace std;

void max_min_ele(int arr[], int n)
{
    int max,min;
    max=min=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
        if(arr[i]<min)
        min=arr[i];
    }
    cout<<"\n Max element is: "<<max;
    cout<<"\n Min element is: "<<min;
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
    max_min_ele(arr,n);
}