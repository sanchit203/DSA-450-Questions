#include<iostream>
#include"Queue.h"
using namespace std;

struct element{
    node *data;
    element *next;
};

class linkedliststack
{
    element *top;
    public:
    linkedliststack()
    {
        top = NULL;
    }
    
    void push(node *data)
    {
        element *temp = new element;
        if(temp==NULL)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        temp->data = data;
        temp->next = top;
        top= temp;
    }

    void display()
    {
        element *t = top;
        while(t)
        {
            cout<<t->data->x<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    node* pop()
    {
        if(top==NULL)
        {
            cout<<"Stack underflow"<<endl;
            return NULL;
        }
        element *temp = top;
        top =top->next;
        node *x = temp->data;
        delete temp;
        temp= NULL;
        return x;
    }

    int isEmpty()
    {
        if(top==NULL)
            return 1;
        return 0;
    }
};