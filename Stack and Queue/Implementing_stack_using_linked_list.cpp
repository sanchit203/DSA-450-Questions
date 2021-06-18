#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
} *s;

void push()
{
    node *t=new node;
    if(t==NULL)
    {
        cout<<"Stack overflow!";
        exit(1);
    }
    else
    {
        cout<<"Enter the value to insert: ";
        cin>>t->data;
        t->next=s;
        s=t;
    }
    return;
}

void pop()
{
    if(!s)
    {
        cout<<"Stack underflow!"<<endl;
        exit(1);
    }
    node *p=s;
    s=s->next;
    cout<<"Popped out value is: "<<p->data<<endl;
    delete p;
    return;
}

void display()
{
    node *p = s;
    if(p==NULL)
    {
        cout<<"Stack underflow!";
        exit(1);
    }
    cout<<"Current stack: ";
    while(p)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    system("cls");
    int choose;
    label:
    cout<<"Enter 1 to insert, 2 to delete and 3 for display: ";
    cin>>choose;
    switch (choose)
    {
    case 1: push();
            break;
    case 2: pop();
            break;
    case 3: display();
            break;
    }
    cout<<endl<<"If you want to choose again enter 1 otherwise enter 0: ";
    cin>>choose;
    if(choose==1)
    goto label;
    return 0;
}