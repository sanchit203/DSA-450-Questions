#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

class Solution
{
    public:
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *p, *q, *r, *third;
        int n,m,k;
        k=0;
        n=m=1;
        p=first;
        q=NULL;
        r=NULL;
        while(p)
        {
            q=p;
            p=p->next;
            q->next=r;
            r=q;
            n++;
        }
        first=q;
        
        p=second;
        q=NULL;
        r=NULL;
        while(p)
        {
            q=p;
            p=p->next;
            q->next=r;
            r=q;
            m++;
        }
        second =q;
        
        
        p=first;
        q=second;
        r=NULL;
        r=new Node(k);
        third=r;
        while(p&&q)
        {
            if(p->data+q->data + k<=9)
            {
                r->data=p->data + q->data +k;
                k=0;
            }
            else
            {
                r->data=(p->data + q->data +k)%10;
                k=1;
            }
            p=p->next;
            q=q->next;
            if(p||q||k==1)
            {
                r->next = new Node(k);
                r=r->next;
            }
        }
        while(p)
        {
            if(p->data + k<=9)
            {
                r->data=p->data+k;
                k=0;
            }
            else
            {
                r->data=0;
                k=1;
            }
            p=p->next;
            if(p||k==1)
            {
                r->next = new Node(k);
                r=r->next;
            }
        }
        while(q)
        {
            if(q->data + k<=9)
            {
                r->data=q->data+k;
                k=0;
            }
            else
            {
                r->data=0;
                k=1;
            }
            q=q->next;
            if(q||k==1)
            {
                r->next = new Node(k);
                r=r->next;
            }
        }
        p=third;
        q=NULL;
        r=NULL;
        while(p)
        {
            q=p;
            p=p->next;
            q->next=r;
            r=q;
            m++;
        }
        third =q;
        return third;
    }
};

int main()
{
    system("cls");
    int n, m;
    cout<<"Enter no. of elements of first linked list: ";
    cin>>n;
    cout<<"Enter elements of first linked list: ";
    Node* first = buildList(n);
    cout<<"Enter no. of elements of second linked list: ";
    cin>>m;
    cout<<"Enter elements of second linked list: ";
    Node* second = buildList(m);
    Solution ob;
    Node* res = ob.addTwoLists(first,second);
    cout<<"Sum of numbers represnted as linked list is: ";
    printList(res);
    return 0;
}