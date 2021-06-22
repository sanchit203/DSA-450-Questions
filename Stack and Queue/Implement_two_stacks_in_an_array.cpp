#include<bits/stdc++.h>

using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};

int main()
{
    system("cls");
    twoStacks *sq = new twoStacks();
    int choose;
    label:
    cout<<"Enter on which stack you want to do operation(1 for stack1 and 2 for stack2): ";
    int stack_no;
    cin>>stack_no;
    cout<<"Enter 1 for push 2 for pop: ";
    int QueryType=0;
    cin>>QueryType;
    if(QueryType==1)
    {
        cout<<"Enter value to be inserted: ";
        int a;
        cin>>a;
        if(stack_no ==1)
        sq->push1(a);
        else if(stack_no==2)
        sq->push2(a);
    }
    else if(QueryType==2)
    {
    	if(stack_no==1)
        cout<<"Popped out value from stack1: "<<sq->pop1()<<" "<<endl;
        else if(stack_no==2)
        cout<<"Popped out value from stack2: "<<sq->pop2()<<" "<<endl;
    }
    cout<<endl<<"Enter 1 to do operations again or enter 0 to quit: ";
    cin>>choose;
    if(choose==1)
    goto label;
    else
    return 0;
}

void twoStacks :: push1(int x)
{
    top1++;
    arr[top1]=x;
}

void twoStacks ::push2(int x)
{
    top2--;
    arr[top2]=x;
}

int twoStacks ::pop1()
{
    if(top1==-1)
    return -1;
    int x = arr[top1];
    top1--;
    return x;
}

int twoStacks :: pop2()
{
    if(top2==size)
    return -1;
    int x= arr[top2];
    top2++;
    return x;
}