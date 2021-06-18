#include<iostream>
#include<stdlib.h>

using namespace std;

void sort012(int a[], int n)
{
  int i,j,k,l;
  i=j=k=0;
  for(l=0;l<n;l++)
  {
      if(a[l]==0)
      i++;
      else if(a[l]==1)
      j++;
      else
      k++;
  }
  for(l=0;l<i;l++)
  a[l]=0;
  for(l=i;l<i+j;l++)
  a[l]=1;
  for(l=i+j;l<n;l++)
  a[l]=2;
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
    cout<<"\n Enter the elements(from 0, 1 and 2) of array: ";
    for(int i=0; i<n; i++)
    cin>>arr[i];
    sort012(arr,n);
    cout<<"\n Sorted array is: ";
    printarray(arr,n);
    return 0;
}