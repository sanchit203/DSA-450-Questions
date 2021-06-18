#include<bits/stdc++.h>

using namespace std;

//Given an array of n elements that contains elements from 0 to n-1, with any of these numbers appearing any number of times. 
//Find these repeating numbers in O(n) and using only constant memory space.Given an array of n elements that contains elements from 0 to n-1, with any of these numbers appearing any number of times.
// Find these repeating numbers in O(n) and using only constant memory space.

void duplicate_element(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[abs(a[i])]>=0)
        a[abs(a[i])]=-a[abs(a[i])];
        else
        {
            cout<<"\n Repeating element is: "<<abs(a[i]);
        }
        
    }
}

int main()
{
    system("cls");
    int n;
    cout<<"\n Enter the no. of elements: ";
    cin>>n;
    int a[n];
    cout<<"\n Enter the elements of array: ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    duplicate_element(a,n);
    return 0;
}