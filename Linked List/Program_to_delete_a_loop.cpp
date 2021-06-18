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

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

class Solution
{
    public:
    void removeLoop(Node* head)
    {
        Node *p, *q;
        p=q=head;
        if(head==NULL)
        return;
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
        q->next=NULL;
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
    ob.removeLoop(head);
    if( isLoop(head) || length(head)!=n )
        cout<<"Loop is still there";
    else
        cout<<"Loop deleted";
	return 0;
}