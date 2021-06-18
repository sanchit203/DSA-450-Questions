#include<bits/stdc++.h>

using namespace std;

int sb(int a[], int n, int x)
{
    int length,i,j,sum;
    length=INT_MAX;
    i=j=sum=0;
    while(i<n&&j<n)
    {
        if(i==j)
        {
            sum=a[i];
            if(sum>x)
            {
                length=1;
                return length;
            }
            else j++;
        }
        else
        {
            sum=sum+a[j];
            if(sum<=x)
            j++;
            else if(sum>x)
            {
                length=min(length,j-i+1);
                sum=sum-a[i];
                i++;
                sum=sum-a[j];
            }
        }
    }return length;
}

int main()
{
    system("cls");
    int N,M;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>N;
    int Arr[N];
    cout<<"\n Enter the elements of array: ";
    for(int i=0;i<N;i++)
    cin>>Arr[i];
    cout<<"\n Enter the value of sum: ";
    cin>>M;
    cout<<"\n Minimum length of subarray with sum greater than "<<M<<" is "<<sb(Arr,N,M);
    return 0;
}