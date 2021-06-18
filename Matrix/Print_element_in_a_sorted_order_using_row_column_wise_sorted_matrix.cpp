#include <bits/stdc++.h>
using namespace std;

/* Given an NxN matrix Mat. Sort all elements of the matrix. */

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    vector<int> A(N*N);int K=0;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    A[K++]=Mat[i][j];
    K=0;
    sort(A.begin(),A.end());
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    Mat[i][j]=A[K++];
    
    return Mat;
}

int main()
{
    system("cls");
    cout<<"Enter no. of rows or columns: ";
    int r;
    cin>>r;
    vector<vector<int>> matrix(r, vector<int>(r));
    cout<<"Enter elements of array: "<<endl;
    for(int i = 0; i < r; ++i)
    for(int j = 0;j < r; ++j)
    cin>>matrix[i][j];
    matrix = sortedMatrix(r,matrix);
    cout<<"Sorted matrix is:"<<endl;
    for(int i=0;i<r;i++)
    {    
        for(int j=0;j<r;j++)
        cout<<matrix[i][j]<<" ";
        cout<<endl;
    }    
    return 0;
}