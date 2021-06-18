#include<bits/stdc++.h>

using namespace std;

void commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    int D[n1+n2+n3],i,j,k,l;
    i=j=k=l=0;
    while(i<n1&&j<n2&&k<n3)
    {
        if(A[i]==B[j]&&B[j]==C[k])
        {
            cout<<A[i]<<" ";
            i++;
            j++;
            k++;
        }
        if(A[i]>B[j])
        {
            if(A[i]>C[k])
            {
                j++;
                k++;
            }
            else if(A[i]<C[k])
            {
                i++;
                j++;
            }
            else
            j++;
        }
        else if(B[j]>C[k])
        {
            if(B[j]>A[i])
            {
                i++;
                k++;
            }
            else if(B[j]<A[i])
            {
                j++;
                k++;
            }
            else if(B[j]==A[i])
            k++;
        }
        else if(C[k]>A[i])
        {
            if(C[k]>B[j])
            {
                i++;
                j++;
            }
            else if(C[k]<B[j])
            {
                i++;
                k++;
            }
            else
            i++;
        }
    }
    return;
}

int main()
{
    system("cls");
    int n1,n2,n3,i;
    cout<<"\n Enter no. of elements of first array: ";
    cin>>n1;
    int A[n1];
    cout<<"\n Enter elements of first array: ";
    for(i=0; i<n1; i++)
    cin>>A[i];
    cout<<"\n Enter no. of elements of second array: ";
    cin>>n2;
    int B[n2];
    cout<<"\n Enter elements of second array: ";
    for(i=0; i<n2; i++)
    cin>>B[i];
    cout<<"\n Enter no. of elements of third array: ";
    cin>>n3;
    int C[n3];
    cout<<"\n Enter elements of first array: ";
    for(i=0; i<n3; i++)
    cin>>C[i];
    commonElements(A,B,C,n1,n2,n3);
    return 0;
}