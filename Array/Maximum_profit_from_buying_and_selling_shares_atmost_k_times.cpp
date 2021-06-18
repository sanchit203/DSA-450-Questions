#include<bits/stdc++.h>

using namespace std;

int MaxProfit(int a[], int n, int k)
{
    int minv, maxv,maxd,i,z=0;
    minv=maxv=a[0];
    maxd=0;
    i=1;
    int Profit[n]={0};
    while(maxd!=n-1)
    {
        if(i==n)
        {
            i= ++maxd;
            minv=maxv=a[maxd];
            Profit[++z]=0;
            i++;
        }
        else if(minv>=a[i])
        {
            Profit[++z]=0;
            i=++maxd;
            minv= a[i];
            maxv=minv;
            i++;
        }
        else if(maxv<a[i])
        {
            maxv=a[i];
            if(maxv-minv>Profit[z])
            {
                Profit[z]=maxv-minv;
                maxd=i;
            }
            i++;
        }
        else
        {
            i++;
        }
        
    }
    sort(Profit,Profit+n);
    int sum=0;
    for(i=n-1;i>n-1-k;i--)
    {
        sum= sum + Profit[i];
    }
    return sum;
}

int main()
{
    system("cls");
    int n,k;
    cout<<"\n Enter no. of elements: ";
    cin>>n;
    int A[n];
    cout<<"\n Enter elements: ";
    for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"\n Enter the value of K: ";
    cin>>k;
    cout<<"\n Max profit by selling a share atmost k times is : "<<MaxProfit(A,n,k);
    return 0;
}