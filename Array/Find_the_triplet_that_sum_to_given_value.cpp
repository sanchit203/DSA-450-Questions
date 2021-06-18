#include<bits/stdc++.h>

using namespace std;

bool find3Numbers(int a[], int n, int X)
{
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    {
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            if(a[j]+a[k]>X-a[i])
            k--;
            else if(a[j]+a[k]<X-a[i])
            j++;
            else
            return 1;
        }
    }
    return 0;
}

int main()
{
    system("cls");
    int n,k;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>n;
    cout<<"\n Enter the value of sum of triplets: ";
    cin>>k;
    int A[n];
    cout<<"\n Enter elements of array: ";
    for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"\n Is there any triplets which sums to given value: ";
    if(find3Numbers(A,n,k))
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}