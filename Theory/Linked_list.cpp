#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
    int data;
    node *next;
};

class SingleLinkedlist
{
    node *first;
    public:
    SingleLinkedlist()
    {
        first= NULL;
    }
    void create(int n)
    {
        node *t, *last;
        cout<<"Enter "<<n<<" elements of linked list: ";
        for(int i=0;i<n;i++)
        {
            t = new node;
            cin>>t->data;
            t->next =NULL;
            if(first==NULL)
                first=last=t;
            else
            {
                last->next =t;
            }
            last=t;
        }
    }
    void display()
    {
        cout<<"Linked list: ";
        node *t = first;
        while(t)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
    
    int count()
    {
        node *t= first;
        int c=0;
        while(t)
        {
            c++;
            t= t->next;
        }
        return c;
    }

    int sum()
    {
        node *t= first;
        int sum=0;
        while(t)
        {
            sum= sum + t->data;
            t = t->next;
        }
        return sum;
    }

    int max()
    {
        node *t= first;
        int max=INT32_MIN;
        while(t)
        {
            if(max<t->data)
                max = t->data;
            t = t->next;
        }
        return max;
    }

    void search(int ele)
    {
        node *t = first;
        while(t)
        {
            if(t->data == ele)
            {
                cout<<"Element found"<<endl;
                return;
            }
            t =t->next;
        }
        cout<<"Element not found"<<endl;
        return;
    }

    void improvSrch(int ele)
    {
        node *t = first;
        node *q = NULL;
        while(t)
        {
            if(t->data == ele)
            {
                if(q)
                {
                    q->next = t->next;
                    t->next = first;
                    first = t;
                }
                cout<<"element found"<<endl;
                return;
            }
            q= t;
            t =t ->next;
        }
        cout<<"Element not found"<<endl;
        return;
    }

    void insert(int pos, int ele)
    {
        node *t = new node;
        t->data = ele;
        t->next = NULL;
        if(pos == 0)
        {
            t->next = first;
            first = t;
            return;
        }
        else
        {
            if(first)
            {
                node *z= first;
                pos = pos-1;
                while(pos-- && z->next)
                z= z->next;
                t->next = z->next;
                z->next = t;
            }
        }
    }

    void insertinsorted(int ele)
    {
        node *t = first;
        node *q= NULL;
        node *z = new node;
        z->data = ele;
        z->next = NULL;
        if(t->data > ele)
        {
            z->next = t;
            first = z;
            return;
        }
        while(t)
        {
            if(t->data > ele)
            {
                q->next = z;
                z->next = t;
                return;
            }
            q= t;
            t = t->next;
        }
        q->next = z;
    }

    int Delete(int pos)
    {
        if(first)
        {
            node *t = first;
            if(pos == 1)
            {
                int x = first ->data;
                first = first->next;
                delete t;
                t= NULL;
                return x;
            }
            pos--;
            node *q = NULL;
            while(pos-- && t)
            {
                q=t;
                t = t->next;
            }
            if(t==NULL)
            return -1;
            int x = t->data;
            q->next = t->next;
            delete t;
            t= NULL;
        }
        return -1;
    }

    void checksort()
    {
        node *t = first;
        while(t->next)
        {
            if(t->data > t->next->data)
            {
                cout<<"Not sorted"<<endl;
                return;
            }
            t = t->next;
        }
        cout<<"Sorted"<<endl;
        return;
    }

    void RemDup()
    {
        node *t= first;
        node *q = t->next;
        while(q)
        {
            if(q->data == t->data)
            {
                t->next = q->next;
                delete q;
                q= t->next;
            }
            else
            {
                t= q;
                q= q->next;
            }
        }
    }

    void reverse()
    {
        node *p = first->next;
        node *q = first;
        node *r = NULL;
        while(p)
        {
            q->next= r;
            r= q;
            q= p;
            p= p->next;
        }
        q->next = r;
        first = q;
    }

    void concat(SingleLinkedlist a)
    {
        node * t= first;
        while(t->next)
            t=t->next;
        t->next = a.first;
    }

    void merge(SingleLinkedlist a)
    {
        node *third = NULL;
        node *last = NULL;
        while(first && a.first)
        {
            if(first ->data <= a.first->data)
            {
                if(!third)
                    third = first;
                else
                    last ->next = first;
                last = first;
                first = first ->next;
                last ->next = NULL;
            }
            else
            {
                if(!third)
                    third = a.first;
                else
                    last ->next = a.first;
                last = a.first;
                a.first = a.first->next;
                last ->next = NULL;
            }
        }
        while(first)
        {
            last->next = first;
            last = first;
            first = first ->next;
            last ->next = NULL;
        }
        while(a.first)
        {
            last ->next = a.first;
            last = a.first;
            a.first = a.first->next;
            last ->next = NULL;
        }
        first = third;
    }
};

class CircularLinkedlist{
    node *head;
    public:
    CircularLinkedlist()
    {
        head = NULL;
    }
    void create(int n)
    {
        node *z = head;
        cout<<"Enter elements: ";
        for(int i=0;i<n;i++)
        {
            node *t = new node;
            cin>>t->data;
            if(head == NULL)
                head = t;
            else
                z->next = t;
            z= t;
            t->next = head;
        }
    }

    void display()
    {
        node *t= head;
        cout<<"Circular linked list: ";
        do
        {
            cout<<t->data<<" ";
            t = t->next;
        } while (t!=head);
        cout<<endl;
    }

    void insert(int pos, int ele)
    {
        node *p = head;
        node *t = new node;
        t->data = ele;
        if(pos == 0)
        {
            while(p->next!=head)
                p=p->next;
            t->next = head;
            p->next = t;
            head = t;
            return;
        }
        pos = pos-1;
        while(pos-- && p->next)
            p= p->next;
        t->next = p->next;
        p->next = t;
    }

    int Delete(int pos)
    {
        node *p = head;
        node *q = NULL;
        int x;
        if(pos == 1)
        {
            while(p->next != head)
                p=p->next;
            q=head;
            head = head->next;
            p->next = head;
            x = q->data;
            delete q;
            q= NULL;
            return x;
        }
        pos--;
        while(pos--)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
};

int main()
{
    system("cls");
    SingleLinkedlist ob;
    ob.create(5);
    ob.display();
    cout<<ob.count()<<endl;
    cout<<ob.sum()<< endl;
    cout<<ob.max()<<endl;
    ob.search(4);
    ob.display();
    ob.improvSrch(5);
    ob.display();
    ob.insert(0, 0);
    ob.display();
    ob.insert(3, 0);
    ob.display();
    SingleLinkedlist ob2;
    ob2.create(6);
    ob2.insertinsorted(7);
    ob2.display();
    ob2.Delete(7);
    ob2.display();
    ob2.checksort();
    ob.checksort();
    ob2.insertinsorted(2);
    ob2.insertinsorted(2);
    ob2.insertinsorted(2);
    ob2.display();
    ob2.RemDup();
    ob2.display();
    ob2.reverse();
    ob2.display();
    ob2.reverse();
    ob2.display();
    ob.concat(ob2);
    ob.display();
    SingleLinkedlist ob3;
    ob3.create(8);
    ob2.merge(ob3);
    ob2.display();
    ob.display();
    CircularLinkedlist o;
    o.create(8);
    o.display();
    o.insert(2,1);
    o.display();
    o.Delete(1);
    o.Delete(3);
    o.display();
    return 0;
}