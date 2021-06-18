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
    if((m+n)%2==0)
    {
        int x=(m+n)/2;
        int y=(m+n)/2 - 1;
        if(y>=n)
        {
            return (b[y-n]+b[x-n])/2;
        }
        else if(y<n)
        {
            if(x<n)
            return (a[y]+a[x])/2;
            else if(x>=n);
            return (a[y]+b[x-n])/2;
        }
    }
}

int main()
{
    system("cls");
    int n,m;
    cout<<"\n Enter no. of elements of array: ";
    cin>>n;
    int a[n];
    cout<<"\n Enter elements of first array: ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"\n Enter no. of elements of second array: ";
    cin>>m;
    int b[m];
    cout<<"\n Enter elements of second array: ";
    for(int i=0;i<m;i++)
    cin>>b[i];
    cout<<"\n Median of two sorted array of different size is: "<<median(a,n,b,m);
    return 0;
}