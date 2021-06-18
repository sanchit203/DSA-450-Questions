#include<bits/stdc++.h>

using namespace std;

int count_inv(int A[], int n)
{
    int i,j,count=0;
    for(i=1;i<n;i++)
    {
        j=i-1;
        while(j>=0)
        {
            if(A[j]>A[i])
            count++;
            j--;
        }
    }
    return count;
}

int main()
{
    system("cls");
    int n;
    cout<<"\n Enter no. of elements of array: ";
    cin>>n;
    int A[n];
    cout<<"\n Enter elements of the array: ";
    for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"\n Total no. of inversion are: "<<count_inv(A,n);
    return 0;
}