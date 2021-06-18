#include<bits/stdc++.h>

using namespace std;

/* Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space. */

int** rotateBy90(int **Arr, int n)
{
    int A[n*n],i,j,k=0;
    for(i=0;i<n;i++)
    for(j=n-1;j>=0;j--)
    A[k++]= Arr[j][i];
    k=0;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    Arr[i][j]=A[k++];
    return Arr;
}

void display(int **Arr, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<Arr[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    system("cls");
    int n;
    cout<<"Enter no. of rows or columns of square matrix: "<<endl;
    cin>>n;
    int **A;
    A= new int*[n];
    for(int i=0;i<n;i++)
    A[i]= new int[n];
    cout<<"Enter elements of matrix: "<<endl;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>A[i][j];
    A = rotateBy90(A,n);
    display(A,n);
    return 0;
}