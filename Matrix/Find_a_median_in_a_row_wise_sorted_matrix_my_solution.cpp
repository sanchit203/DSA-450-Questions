#include <bits/stdc++.h>
using namespace std;

/* Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix. */

int median(vector<vector<int>> &matrix, int r, int c)
{
    vector<int> A(r*c);int k=0;
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    A[k++]=matrix[i][j];
    
    sort(A.begin(),A.end());
    
    if(r*c%2==0)
    return (A[r*c/2 -1] + A[r*c/2])/2;
    
    else
    return A[r*c/2];// code here          
}

int main()
{
    system("cls");
    cout<<"Enter no. of rows and columns: ";
    int r, c;
    cin>>r>>c;
    vector<vector<int>> matrix(r, vector<int>(c));
    cout<<endl<<"Enter elements of array: "<<endl;
    for(int i = 0; i < r; ++i)
    for(int j = 0;j < c; ++j)
    cin>>matrix[i][j];
    cout<<endl<<"Median of the array is: "<<median(matrix, r, c)<<endl;
    return 0;
}