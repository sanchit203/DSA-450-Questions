#include<bits/stdc++.h>

using namespace std;

int min_height(int A[], int n, int k)
{
    if(n==1)
    return 0;
    sort(A,A+n);//
    
    int init_min,init_max,init_diff;
    init_min=A[0];
    init_max=A[n-1];
    init_diff=init_max-init_min;

    //Subtracting k from init_max and adding k to init_min
    init_min+=k;
    init_max-=k;

    //Swapping if init_min>init_max
    if(init_min>init_max)
    {
        int temp=init_min;
        init_min=init_max;
        init_max=init_min;
    }

    for(int i=1;i<n-1;i++)
    {
        int subtract=A[i]-k;
        int add= A[i]+k;

        if((subtract>=init_min)||(add<=init_max))
        continue;

        else if(init_max-subtract<=add-init_min)
        init_min=subtract;

        else
        init_max=add;
    }

    return min(init_diff, init_max-init_min);
}

int main()
{
    system("cls");
    int N,K;
    cout<<"\n Enter the no. of elements: ";
    cin>>N;
    int A[N];
    cout<<"\n Enter the elements: ";
    for(int i=0;i<N;i++)
    cin>>A[i];
    cout<<"\n Enter the NO. by which you wants to change the element: ";
    cin>>K;
    cout<<"\n Maximum difference between elements after minimizing the difference by "<<K<<" is: "<<min_height(A,N,K);
    return 0;
}