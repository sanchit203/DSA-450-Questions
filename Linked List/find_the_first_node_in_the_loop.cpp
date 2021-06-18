#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution
{
    public:
    int startpos(Node* head)
    {
        Node *p, *q;
        p=q=head;
        do
        {
            q=q->next;
            p=p->next->next;
        }while(p!=q);
        int k=1;
        while(p->next!=q)
        {
            p=p->next;
            k++;
        }
        p=q=head;
        for(int i=0;i<k-1;i++)
        q=q->next;
        while(q->next!=p)
        {
            p=p->next;
            q=q->next;
        }
        q=head;
        k=1;
        while(q!=p)
        {
            k++;
            q=q->next;
        }
        return k;
    }
};

int main()
{
    system("cls");
    int n, num;
    cout<<"Enter no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    Node *head, *tail;
    cin>> num;
    head = tail = new Node(num);
    for(int i=0 ; i<n-1 ; i++)
    {
        cin>> num;
        tail->next = new Node(num);
        tail = tail->next;
    }
    cout<<"Enter posiion(must be less then no. of elements) where you want to make loop: ";
    int pos;
    cin>> pos;
    loopHere(head,tail,pos);
    Solution ob;
    cout<<"Starting position of loop is: "<<ob.startpos(head);
    return 0;
}