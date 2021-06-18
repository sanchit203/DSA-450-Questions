#include<bits/stdc++.h>

using namespace std;

int minjumps(int a[], int n)
{
    if(n==1)
    return 0;
    if(a[0]==0)
    return -1;
    int maxreach=a[0];
    int step=a[0];
    int jump=1;

    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        return jump;

        maxreach= max(maxreach, i+a[i]);

        step--;

        if(step==0)
        {
            jump++;

            if(i>=maxreach)
            return -1;

            step= maxreach-i;
        }
    }

    return -1;
}

int main()
{
    system("cls");
    int n;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>n;
    cout<<"\n Enter the elements of array: ";
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"\n Minimum no. of jumps to reach the end of array is: "<<minjumps(a,n);
    return 0;
}