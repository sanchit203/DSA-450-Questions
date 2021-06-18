#include<bits/stdc++.h>

using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    sort(a1,a1+n);
    sort(a2,a2+m);
    int i,j;
    i=j=0;
    while(i<n&&j<m)
    {
        if(a1[i]>a2[j])
        return "No";
        else if(a1[i]==a2[j])
        {
            i++;
            j++;
        }
        else
        i++;
    }
    if(j==m)
    return "Yes";
    else
    return "No";
}

int main()
{
    system("cls");
    int n,k;
    cout<<"\n Enter no. of elements of first array: ";
    cin>>n;
    int A1[n];
    cout<<"\n Enter elements of first array: ";
    for(int i=0;i<n;i++)
    cin>>A1[i];
    cout<<"\n Enter no. of elements of second array: ";
    cin>>k;
    int A2[k];
    cout<<"\n Enter elements of second array: ";
    for(int i=0;i<k;i++)
    cin>>A2[i];
    cout<<"\n Is array subset of anohter array? "<<isSubset(A1,A2,n,k);
    return 0;
}