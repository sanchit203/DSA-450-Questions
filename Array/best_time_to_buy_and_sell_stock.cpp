#include<bits/stdc++.h>

using namespace std;

int maxProfit(int a[], int n)
{
    int minv, maxv, maxp;
    minv=maxv=a[0];
    maxp=0;
    for(int i=1;i<n;i++)
    {
        if(minv>a[i])
        {
            minv= a[i];
            maxv=minv;
        }
        else if(maxv<a[i])
        {
            maxv=a[i];
        }
        maxp=max(maxp,(maxv-minv));
    }
    return maxp;
}

int main()
{
    system("cls");
    int n;
    cout<<"\n Enter no. of elements: ";
    cin>>n;
    int A[n];
    cout<<"\n Enter elements: ";
    for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"\n Max profit is: "<<maxProfit(A,n);
    return 0;
}