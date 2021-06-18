#include<bits/stdc++.h>

using namespace std;

/* Given a boolean 2D array of n x m dimensions where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's. */

int roeWithMax1(int **a, int n, int m)
{
    int i,j,index=-1;
	i=0;j=m-1;
	while(i<n&&j<m)
	{
	    if(a[i][j]==1)
	    {
	        j--;
	        index= i;
	    }
	    else
	    i++;
	} return index;
}

int main()
{
    system("cls");
    int n,m;
    cout<<"Enter no. of rows and column: ";
    cin>>n>>m;
    int *A[n];
    for(int i=0;i<n;i++)
    A[i]= new int[m];
    cout<<endl<<"Enter element of array as 1 or 0 - "<<endl;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>A[i][j];
    cout<<endl<<"Index based row with maximum no. of 1 is: "<<roeWithMax1(A,n,m);
    return 0;
}