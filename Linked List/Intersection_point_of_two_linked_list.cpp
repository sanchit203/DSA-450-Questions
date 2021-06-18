#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

int main()
{
    system("cls");
    int n1,n2,n3;
    cout<<"Enter no. of elements of first linked list, second linked list & no. of common elements:";
    cin>>n1>>n2>>n3;
    cout<<"Enter elements of first linked list: ";
    Node* head1 = inputList(n1);
    cout<<"Enter elements of second list: ";
    Node* head2 = inputList(n2);
    cout<<"Enter common elements: ";
    Node* common = inputList(n3);
    
    Node* temp = head1;
    while(temp!=NULL && temp->next != NULL)
        temp = temp->next;
    if(temp!=NULL) temp->next = common;
    
    temp = head2;
    while(temp!=NULL && temp->next != NULL)
        temp = temp->next;
    if(temp!=NULL) temp->next = common;
    
    cout <<"Intersection point of both linked list is: " <<intersectPoint(head1, head2) << endl;
    return 0;
}

int intersectPoint(Node* head1, Node* head2)
{
    Node *p, *q;
    p=head1;
    q=head2;
    int n,m,d;
    n=m=0;
    while(p)
    {
        p=p->next;
        n++;
    }
    while(q)
    {
        q=q->next;
        m++;
    }
    p=head1;
    q=head2;
    if(n>m)
    {
        d=n-m;
        for(int i=0;i<d;i++)
        {
            p=p->next;
        }
    }
    else
    {
        d=m-n;
        for(int i=0;i<d;i++)
        q=q->next;
    }
    while(p&&q)
    {
        if(p->next==q->next)
        return p->next->data;
        p=p->next;
        q=q->next;
    }
    return -1;
}

