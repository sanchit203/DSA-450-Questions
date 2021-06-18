//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
}

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node *p, *q, *r;
        p=head;
        q=NULL;
        r=NULL;
        while(p)
        {
            q=p;
            p=p->next;
            q->next=r;
            r=q;
        }
        head=q;
        p=head;
        q=NULL;
        r=NULL;
        while(p)
        {
            if(p->data<9)
            {
                p->data=p->data+1;
                break;
            }
            else
            {
                if(p->next==NULL)
                {
                    p->data=p->data+1;
                }
                else
                p->data=0;
            }
            p=p->next;
        }
        p=head;
        while(p)
        {
            q=p;
            p=p->next;
            q->next=r;
            r=q;
        }
        head=q;
        return head;
    }
};

int main() 
{ 
    system("cls");
    cout<<"Enter the no. ";
    string s;
    cin>>s;
    Node* head = new Node( s[0]-'0' );
    Node* tail = head;
    for(int i=1; i<s.size(); i++)
    {
        tail->next = new Node( s[i]-'0' );
        tail = tail->next;
    }
    Solution ob;
    head = ob.addOne(head);
    cout<<"No. after adding one to it: ";
    printList(head); 
    return 0; 
}