#include<bits/stdc++.h>

using namespace std;

int Maxprofit(int a[],int n)
{
    int minv, maxv,maxd,mind, maxp,temp_mind=0;
    minv=maxv=a[0];
    maxp=0;
    maxd=mind=0;
    for(int i=1;i<n;i++)
    {
        if(minv>=a[i])
        {
            minv= a[i];
            maxv=minv;
            temp_mind=i;
        }
        else if(maxv<a[i])
        {
            maxv=a[i];
            if(maxv-minv>maxp)
            {
                maxp=maxv-minv;
                maxd=i;
                mind=temp_mind;
            }
        }
    }
    int maxp2=0;
    minv=maxv=a[maxd];
    for(int i=maxd+1;i<n;i++)
    {
        if(minv>a[i])
        {
            minv= a[i];
            maxv=minv;
        }
        else if(maxv<a[i])
        {
            maxv=a[i];
        }
        maxp2=max(maxp2,(maxv-minv));
    }
    int maxp3=0;
    minv=maxv=a[0];
    for(int i=1;i<mind;i++)
    {
        if(minv>a[i])
        {
            minv= a[i];
            maxv=minv;
        }
        else if(maxv<a[i])
        {
            maxv=a[i];
        }
        maxp3=max(maxp3,(maxv-minv));
    }
    if(maxp2>maxp3)
    return maxp+maxp2;
    return maxp+maxp3;
}

int main()
{
    system("cls");
    int n;
    cout<<"\n Enter no. of elements: ";
    cin>>n;
    int A[n];
    cout<<"\n Enter elements: ";
    for(int i=0;i<n;i++)
    cin>>A[i];
    cout<<"\n Max profit by selling a share atmost twice is : "<<Maxprofit(A,n);
    return 0;
}