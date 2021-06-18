#include<bits/stdc++.h>

using namespace std;

int findmindiff(int a[], int n, int m)
{
    sort(a,a+n);
    int diff=INT32_MAX;
    for(int i=0;i+m-1<n;i++)
    {
        diff=min(diff,a[i+m-1]-a[i]);
    }
    return diff;
}

int main()
{
    system("cls");
    int N,M;
    cout<<"\n Enter the no. of packets of choclates: ";
    cin>>N;
    int Arr[N];
    cout<<"\n Enter the no. of choclates in each packets: ";
    for(int i=0;i<N;i++)
    cin>>Arr[i];
    cout<<"\n Enter no. of students: ";
    cin>>M;
    cout<<"\n Minimum difference between maximum choclates and minimum choclates is: "<<findmindiff(Arr,N,M);
    return 0;
}