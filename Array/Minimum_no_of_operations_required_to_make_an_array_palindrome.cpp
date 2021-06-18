#include<bits/stdc++.h>

using namespace std;

int oper_count(int a[], int n)
{
    int count=0;
    int i,j=n-1;
    i=0;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
        else if(a[i]<a[j])
        {
            a[i+1]=a[i]+a[i+1];
            count++;
            i++;
        }
        else
        {
            a[j-1]=a[j]+a[j-1];
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
    cout<<"\n Enter elements of array: ";
    for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"\n Minimum no. of operations required to make this array palindrome is: "<<oper_count(A,n);
    return 0;
}