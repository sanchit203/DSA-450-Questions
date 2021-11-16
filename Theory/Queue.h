#include<iostream>
using namespace std;

struct node
{
    node *lchild;
    int x;
    node *rchild;
};

struct Element
{
    node *data;
    Element *next;
};

class LLQueue{
    Element *f;
    Element *r;

    public:
    LLQueue()
    {
        f = NULL;
        r = NULL;
    }

    void enqueue(node *x)
    {
        Element *temp = new Element;
        if(temp==NULL)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        temp->data = x;
        temp->next = NULL;
        if(f == NULL)
            f = r = temp;
        else
        {
            r->next = temp;
            r = temp;
        }
    }

    node* dequeue()
    {
        node *z;
        if(f==NULL)
        {
            cout<<"Queue underflow"<<endl;
            return NULL;
        }
        Element *temp = new Element;
        temp = f;
        f = f->next;
        z= temp->data;
        delete temp;
        temp=NULL;
        return z;
    }

    void Display()
    {
        Element *temp = f;
        while(temp)
        {
            cout<<temp->data->x<<' ';
            temp = temp->next;
        }
        cout<<endl;
    }

    int isEmpty()
    {
        if(f==NULL)
            return 1;
        return 0;
    }
};