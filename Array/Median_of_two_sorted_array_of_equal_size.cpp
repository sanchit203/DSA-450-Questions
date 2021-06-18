#include<bits/stdc++.h>

using namespace std;

int median(int a[], int n, int b[], int m)
{
    int temp,j, i=0;
    for(;i<n;i++)
    {
        if(a[i]>=b[0])
        {
            if (a[i]==b[0])
            i++;
            temp=a[i];
            a[i]=b[0];
            for(j=0;b[j]<temp&&j<m;j++)
            b[j]=b[j+1];
            b[j-1]=temp;
        }
    }
    return (a[n-1]+b[0])/2;
}

int main()
{
    system("cls");
    int n;
    cout<<"\n Enter no. of elements of array: ";
    cin>>n;
    int a[n];
    cout<<"\n Enter elements of first array: ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int b[n];
    cout<<"\n Enter elements of second array: ";
    for(int i=0;i<n;i++)
    cin>>b[i];
    cout<<"\n Median of two sorted array of equal size is: "<<median(a,n,b,n);
    return 0;
}