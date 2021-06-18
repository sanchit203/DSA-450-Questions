#include<bits/stdc++.h>

using namespace std;

int Next_Perm(int a[],int n)
{
    int i,j,temp=-1;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            temp=a[i];
            break;
        }
    }
    if(temp==-1)
    {
        sort(a,a+n);
        return 0;
    }
    for(j=n-1;j>i;j--)
    {
        if(a[j]>a[i])
        {
            a[i]=a[j];
            a[j]=temp;
            break;
        }
    }
    for(i=i+1,j=n-1;j>i;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    return 1;
}

void printarray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    cout<<arr[i]<<' ';
}
int main()
{
    system("cls");
    int n;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>n;
    int arr[n];
    cout<<"\n Enter the elements of array: ";
    for(int i=0; i<n; i++)
    cin>>arr[i];
    if(Next_Perm(arr,n))
    cout<<"\n Lexicographically next permutation is: ";
    else cout<<"\n Lexicographically next permutaiton is not possible so printing array in ascending order- ";
    printarray(arr,n);
    return 0;
}