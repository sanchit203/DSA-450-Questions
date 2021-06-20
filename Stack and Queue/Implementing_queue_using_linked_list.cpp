#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
} *q, *tail;

void push()
{
    node *t = new node;
    if(t==NULL)
    {
        cout<<"Queue overflow!";
        exit(1);
    }
    cout<<"Enter value to be inserted: ";
    cin>>t->data;
    t->next= NULL;
    if(q==NULL)
    {
        q=t;
        tail=t;
    }
    else{
        tail->next= t;
        tail=t;
    }
    return;
}

void pop()
{
    if(q==NULL)
    {
        cout<<"Queue underflow!";
        exit(1);
    }
    else
    {
        node *t = q;
        q=q->next;
        cout<<"Popoed out value is: "<<t->data<<endl;
        delete t;
    }
}

void display()
{
    node *t = q;
    if(t==NULL)
    {
        cout<<"Queue underflow!";
        exit(1);
    }
    cout<<"Current queue status: ";
    while(t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

int main()
{
    system("cls");
    int choose;
    q = tail =NULL;
    label:
    cout<<"Enter 1 to insert, 2 to delete, 3 to display: ";
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