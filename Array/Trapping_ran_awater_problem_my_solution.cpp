#include<bits/stdc++.h>

using namespace std;

int trappingwater(int a[], int n)
{
    int leftwall=a[0];
    int rightwall=INT32_MIN;
    int j,sum=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>leftwall)
        {
            leftwall=a[i];
            continue;
        }
        j=n-1;
        while(j>=i)
        {
            if(a[j]>rightwall)
            rightwall=a[j];
            j--;
        }
        if(leftwall>rightwall)
        {
            if(rightwall-a[i]>0)
            sum=sum+rightwall-a[i];
        }
        else
        {
            if(leftwall-a[i]>0)
            sum=sum+leftwall-a[i];
        }
        rightwall=INT32_MIN;
    }
    return sum;
}

int main()
{
    system("cls");
    int N;
    cout<<"\n Enter the no. of blocks: ";
    cin>>N;
    int Arr[N];
    cout<<"\n Enter the heights of each block: ";
    for(int i=0;i<N;i++)
    cin>>Arr[i];
    cout<<"\n Maximum Water that can trapped in this block is "<<trappingwater(Arr,N);
    return 0;
}