#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
    int data;
    node *next;
};

class Chaining{
    node **a;
    public:
    Chaining()
    {
        a = new node*[10];
        for(int i=0;i<10;i++)
            a[i] = NULL;
    }

    void Insert(int ele)
    {
        int x = ele%10;
        node *t = new node;
        t->data = ele;
        t->next = NULL;

        if(a[x]==NULL)
            a[x] = t;
        else
        {
            if(a[x]->data >= ele)
            {
                t->next = a[x];
                a[x] = t;
            }
            else
            {
                node *p = a[x];
                while(p->next && p->next->data < ele)
                    p=p->next;
                t->next = p->next;
                p->next = t;
            }
        }
    }

    void Search(int ele)
    {
        int x = ele%10;
        node *p = a[x];
        while(p)
        {
            if(p->data == ele)
            {
                cout<<"Element Found"<<endl;
                return;
            }
            else if(p->data > ele)
            {
                cout<<"Element Not Found"<<endl;
                return;
            }
            p=p->next;
        }
        cout<<"Element Not Found"<<endl;
        return;
    }
};

class LinearProbing{
    int *H;
    public:
    LinearProbing()
    {
        H = new int[10];
        for(int i=0;i<10;i++)
            H[i] = -1;
    }
    int hash(int key)
    {
        return key%10;
    }


    void Insert(int key)
    {
        int i = hash(key);
        if(H[i] == -1)
        {
            H[i] = key;
            return;
        }
        int j=0;
        while(H[(i+j)% 10]!= -1)
            j++;
        H[(i+j)%10] = key;
    }

    int Search(int key)
    {
        int i = hash(key);
        int j=0;
        while(H[(i + j)%10] != key)
        {
            if(H[(i+j)%10] == -1)
                return 0;
            i++;
        }
        return 1;
    }
};

int main()
{
    system("cls");
    Chaining Ob;
    int a[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    for(int i=0;i<9;i++)
        Ob.Insert(a[i]);
    Ob.Search(7);
    
    LinearProbing o;
    o.Insert(12);
    o.Insert(25);
    o.Insert(35);
    o.Insert(26);

    o.Search(36) ? cout<<"Element foud"<<endl : cout<<"Element Not found"<<endl;
    return 0;
}