#include<bits/stdc++.h>

using namespace std;

long long int Max_prod(int A[], int n)
{
    int i,j;
    long long int temp_prod, per_prod=INT32_MIN;
    for(i=0;i<n;i++)
    {
        temp_prod=A[i];
        per_prod=max(per_prod,temp_prod);
        for(j=i+1;j<n;j++)
        {
            temp_prod = temp_prod*A[j];
            per_prod= max(per_prod,temp_prod);
        }
    }
    return per_prod;
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
    cout<<"\n Max product subarray is: "<<Max_prod(A,n);
    return 0;
}