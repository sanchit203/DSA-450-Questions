#include<bits/stdc++.h>

using namespace std;

void merge(int a[], int b[], int n, int m)
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
    return;
}
void printarray(int a[], int b[], int n, int m)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    for(int i=0;i<m;i++)
    cout<<b[i]<<" ";
}

int main()
{
    system("cls");
    int n;
    cout<<"\n Enter no. of elements of first array: ";
    cin>>n;
    int a[n];
    cout<<"\n Enter elements of first array: ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"\n Enter no. of elements of second array: ";
    int m;
    cin>>m;
    int b[m];
    cout<<"\n Enter elements of second array: ";
    for(int i=0;i<m;i++)
    cin>>b[i];
    cout<<"\n Merged array is: ";
    merge(a,b,n,m);
    printarray(a,b,n,m);
    return 0;
}