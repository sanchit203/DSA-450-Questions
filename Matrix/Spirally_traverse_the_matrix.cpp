#include<bits/stdc++.h>

using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    vector<int> A(r*c); int i,row,col,k, boundary;
    boundary = 0; col=c-1;k=0;row=r-1;
    while(k<r*c)
    {
        for(i = boundary; i<=col-boundary; i++)
        {
            A[k++]=matrix[boundary][i];
        }
        for(i = boundary+1; i<=row-boundary; i++)
        {
            A[k++]=matrix[i][col-boundary];
        }
        for(i = col-boundary-1; i>=boundary; i--)
        {
            A[k++]=matrix[row-boundary][i];
        }
        for(i = row-boundary-1; i>=boundary+1; i--)
        {
            A[k++]=matrix[i][boundary];
        }
        boundary++;
    }
    return A;
}

int main()
{
    system("cls");
    int r,c;
    cout<<"Enter no. of rows:"<<endl;
    cin>>r;
    cout<<"Enter no. of column: "<<endl;
    cin>>c;
    vector<vector<int>> A(r);
    cout<<"Enter elements of array: ";
    for(int i=0;i<r;i++)
    {
        A[i].assign(c,0);
        for(int j=0;j<c;j++)
        cin>>A[i][j];
    }
    vector<int> P= spirallyTraverse(A,r,c);
    cout<<"Spirally traversed matrix is: ";
    for(int i=0;i<P.size();i++)
    cout<<P[i]<<" ";
    return 0;
}