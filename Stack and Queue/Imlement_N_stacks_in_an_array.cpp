#include<bits/stdc++.h>
using namespace std;

class Stacks{
    int *arr;
    int *top;
    int *next;
    int free;
    public :
    Stacks(int n, int k)                   //n for size of array and k for no. of stacks
    {
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        free = 0;
        for(int i=0;i<n-1;i++)
        next[i]=i+1;
        next[n-1] = -1;
        for(int i=0;i<k;i++)
        top[i]=-1;
    }
    void push(int x, int k)             // x is element to be pushed and k is on what stack is to be pushed
    {
        if(free==-1)
        {
            cout<<"Stack overflow!";
            exit(1);
        }
        int z = free;
        free = next[z];
        next[z]=top[k-1];
        top[k-1]=z;
        arr[z]=x;
        return;
    }
    int pop(int k)
    {
        if(top[k-1]==-1)
        {
            cout<<"Stack uderflow!";
            exit(1);
        }
        int z= top[k-1];
        top[k-1]=next[z];
        next[z]=free;
        free=z;
        return arr[z];
    }
};

int main()
{
    system("cls");
    int n,k,x;
    cout<<"Enter value of size of array and no. of stacks: ";
    cin>>n>>k;
    Stacks ob(n,k);
    label:
    cout<<"Enter the stack you want to do operation on: ";
    cin>>k;
    cout<<"Enter 1 for push 2 for pop: ";
    cin>>n;
    if(n==1)
    {
        cout<<"Enter the value to be inserted: ";
        cin>>x;
        ob.push(x,k);
    }
    else
    {
        x=ob.pop(k);
        cout<<"Popped out value from stack "<<k<<" is: "<<x<<endl;
    }
    cout<<endl<<"Enter 1 to perform operations again or enter 0 to quit: ";
    cin>>x;
    if(x==1)
    goto label;
    return 0;
}