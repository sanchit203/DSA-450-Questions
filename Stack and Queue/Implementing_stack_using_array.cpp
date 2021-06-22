#include<bits/stdc++.h>
using namespace std;

struct STCK{
    int size;   //For size of array
    int top;    //For position of top
    int *p;     //Pointer for storing address of array
};

void push(STCK *s)
{
    int x;
    cout<<"Enter the value to insert: ";
    cin>>x;
    if(s->top==s->size-1)
    {
        cout<<"Stack overflow!"<<endl;
    }
    else
    {
        s->top++;
        s->p[s->top] = x;
    }
    return;
}

void pop(STCK *s)
{
    if(s->top==-1)
    cout<<"Stack underflow!"<<endl;
    else
    {
        cout<<"Popped out element: "<<s->p[s->top]<<endl;
        s->top--;
    }
}

void display(STCK *s)
{
    cout<<"Current status of stack: ";
    for(int i=0;i<=s->top;i++)
    {
        cout<<s->p[i]<<' ';
    }
    cout<<endl;
    return;
}

void middle(STCK *s)
{
    cout<<"Middle element: ";
    cout<<s->p[s->top/2]<<endl;
    return;
}

int main()
{
    system("cls");
    STCK s;
    int choose;
    cout<<"Enter size of stack: ";
    cin>>s.size;
    s.top = -1;
    s.p = new int[s.size];
    label:
    cout<<"Enter 1 to insert, 2 to delete, 3 to display and 4 to find middle element: ";
    cin>>choose;
    switch (choose)
    {
    case 1: push(&s);
            break;
    case 2: pop(&s);
            break;
    case 3: display(&s);
            break;
    case 4: middle(&s);
    }
    cout<<endl<<"If you want to choose again enter 1 otherwise enter 0: ";
    cin>>choose;
    if(choose==1)
    goto label;
    return 0;
}