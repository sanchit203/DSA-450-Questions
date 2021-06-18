#include<bits/stdc++.h>

using namespace std;

int countOccurence(int arr[], int n, int k)
{
    sort(arr,arr+n);
    int temp,ele_count,occ_count=0;
    ele_count=1;
    temp=INT_MIN;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1]&&arr[i]!=temp)
        {
            ele_count++;
            if(ele_count> n/k)
            {
                occ_count++;
                temp=arr[i];
            }
        }
        else
        ele_count=1;
    }
   return occ_count;
}

int main()
{
    system("cls");
    int N,K;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>N;
    int A[N];
    cout<<"\n Enter the elements of array: ";
    for(int i=0;i<N;i++)
    cin>>A[i];
    cout<<"\n Enter value of K: ";
    cin>>K;
    cout<<"\n No. of elements that appear more than n/k times are: "<<countOccurence(A,N,K);
    return 0;
}