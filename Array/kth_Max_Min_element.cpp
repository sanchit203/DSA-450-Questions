#include<iostream>
#include<stdlib.h>

using namespace std;

void Kth_max_min_ele(int arr[], int l, int r, int k, int p)
{
    int i,a=0,max=arr[0];
    for(i=l+1;i<=r;i++)
    if(arr[i]>max)
    max=arr[i];
    int H[max+1];
    for(i=0;i<=max;i++)
    H[i]=-1;
    for(i=l;i<=r;i++)
    H[arr[i]]=1;
    for(i=1;i<=max;i++)
    if(H[i]==1)
    {
       a++;
       if(a==k)
       break;
    }
    cout<<"\n Kth min element is: "<<i;
    a=0;
    for(i=max;i>=1;i--)
    if(H[i]==1)
    {
       a++;
       if(a==p)
       break;
    }
    cout<<"\n Pth max element is: "<<i;
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
    cout<<"\n Enter the kth min element you want to find: ";
    int k;
    cin>>k;
    cout<<"\n ENter the pth max element you want to find: ";
    int p;
    cin>>p;
    Kth_max_min_ele(arr,0,n-1,k,p);
    return 0;
}