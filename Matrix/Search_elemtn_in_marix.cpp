#include<bits/stdc++.h>

using namespace std;

int matSearch (int N, int M, int **A, int x)
{
    int i=0;
    while(i<N &&A[i][0]<=x)
    i++;
    for(int j=0;j<M;j++)
    if(A[i-1][j]==x)
    return 1;
    return 0;
}

int main()
{
    system("cls");
    int n,m;
    cout<<"Enter no. of rows and columns: ";
    cin>>n>>m;
    cout<<endl;
    int *A[n];
    for(int i=0;i<n;i++)
    A[i]= new int[m];
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>A[i][j];
    cout<<endl<<"Enter element to be found: ";
    int x;
    cin>>x;
    matSearch(n,m,A,x)? cout<<"\nElement found" : cout<<"\n Element not found";
    for(int i=0;i<n;i++)
    free(A[i]);
    return 0;
}