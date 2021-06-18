#include<bits/stdc++.h>

using namespace std;

bool subArrayExits(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        int sum=A[i];
        if(sum==0)
        return true;
        for(int j=i+1;j<n;j++)
        {
            sum=sum+A[j];
            if(sum==0)
            return true;
        }
    }
    return false;
}

int main()
{
    system("cls");
    int n;
    cout<<"\n Enter no. of  elements of array: ";
    cin>>n;
    cout<<"\n Enter elements of array: ";
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    if(subArrayExits(A,n))
    cout<<"\n There are atleast 1 subarray with sum equals to zero.";
    else
    cout<<"\n There are not even a single array with sum equals to zero.";
    return 0;
}