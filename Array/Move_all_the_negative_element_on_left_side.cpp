#include<iostream>
#include<stdlib.h>

using namespace std;

void edit_array(int arr[], int n)
{
    int temp,i=0,j=n-1;
    while(i<j)
    {
        if((arr[j]<0)&&(arr[i]>=0))
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        if(arr[j]>=0)
        j--;
        if(arr[i]<0)
        i++;
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
    edit_array(arr,n);
    cout<<"\n Edited array is: ";
    printarray(arr,n);
    return 0;
}