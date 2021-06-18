#include<iostream>
#include<stdlib.h>
using namespace std;

int union_arr(int A[], int B[], int N, int M)
{
    int i,j;
    i=j=0;
    while((i<N)&&(j<M))
    {
        if(A[i]==B[j])
        {
            j++;
            cout<<A[i]<<' ';
            i++;
        }
        else if(A[i]>B[j])
        {
            cout<<B[j]<<' ';
            j++;
        }
        else
        {
            cout<<A[i]<<' ';
            i++;
        }
    }
    if(i<N)
    {
        while(i<N)
        {
            cout<<A[i]<<' ';
            i++;
        }
    }
    else
    {
        while(j<M)
        {
            cout<<B[j]<<' ';
            j++;
        }
    }
}
int intersection_arr(int A[], int B[], int N, int M)
{
    int i,j;
    i=j=0;
    while((i<N)&&(j<M))
    {
        if(A[i]==B[j])
        {
            j++;
            cout<<A[i]<<' ';
            i++;
        }
        else if(A[i]>B[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    system("cls");
    int N,M;
    cout<<"\n Enter no. of Element of array A: ";
    cin>>N;
    cout<<"\n Enter no. of element of array B: ";
    cin>>M;
    int A[N],B[M];
    cout<<"\n Enter elements of array A: ";
    for(int i=0;i<N;i++)
    cin>>A[i];
    cout<<"\n Enter elements of array B: ";
    for(int i=0;i<M;i++)
    cin>>B[i];
    cout<<"\n Union is: ";
    union_arr(A,B,N,M);
    cout<<"\n Intersection is: ";
    intersection_arr(A,B,N,M);
	return 0;
}