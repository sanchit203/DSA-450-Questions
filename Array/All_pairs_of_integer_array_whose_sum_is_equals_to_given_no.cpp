#include<bits/stdc++.h>

using namespace std;

int count_pairs(int a[], int n, int k)
{
    sort(a,a+n);
    int i,j,pairs=0;
    i=0;j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]>k)
        j--;
        else if(a[i]+a[j]<k)
        i++;
        else
        {
            pairs++;
            if(a[j]==a[j-1])
            {
                int l=j;
                while(a[l-1]==a[l]&&l-1>i)
                {
                    l--;
                    pairs++;
                }
            }
            i++;
        }
    }
    return pairs;   
}

int main()
{
    system("cls");
    int n,k;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>n;
    cout<<"\n Enter the value of sum of pairs: ";
    cin>>k;
    int A[n];
    cout<<"\n Enter elements of array: ";
    for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"\n Total no. of pairs with sum equals to "<<k<<" are: "<<count_pairs(A,n,k);
    return 0;
}