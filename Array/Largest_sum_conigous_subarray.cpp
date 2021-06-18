#include<iostream>
#include<stdlib.h>

using namespace std;

int largest_subarr_sum(int arr[],  int n)
{
    int pmt_max=INT32_MIN; //Smallest value possible
    int temp_max=0;
    for(int i=0;i<n;i++)
    {
        temp_max=temp_max+arr[i];
        if(pmt_max<temp_max)
        pmt_max=temp_max;
        if(temp_max<0)
        temp_max=0;
    }
    return pmt_max;
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
    cout<<"\n Largest subarray sum possible is: "<<largest_subarr_sum(A,N);
    return 0;
}