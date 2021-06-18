#include<bits/stdc++.h>

using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int temp_max, per_max=INT_MIN;
    temp_max=0;
    for(int i=0; i<n;i++)
    {
        temp_max=temp_max+arr[i];
        if(temp_max>per_max)
        {
            per_max=temp_max;
        }
        if(temp_max<0)
        {
            temp_max=0;
        }
    }
    return per_max;
}

int main()
{
    system("cls");
    int N;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>N;
    int A[N];
    cout<<"\n Enter the elements of array: ";
    for(int i=0;i<N;i++)
    cin>>A[i];
    cout<<"\n Largest subarray sum possible is: "<<maxSubarraySum(A,N);
    return 0;
}