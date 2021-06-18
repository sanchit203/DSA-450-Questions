#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node* reverseList(struct Node *head)
{
    struct Node *p, *q, *r;
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
    return head;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    cout<<"Reversed linked list: ";
    while (temp != NULL)
    {
       cout<<temp->data<<" ";
       temp  = temp->next;
    }
}

int main()
{
    system("cls");
    int n,l,firstdata;
    struct Node *head = NULL,  *tail = NULL;
    cout<<"Enter no. of elements of linked list: ";
    cin>>n;
    cout<<"Enter "<<n<<" elements: ";
    cin>>firstdata;
    head = new Node(firstdata);
    tail = head;
    for (int i=1; i<n; i++)
    {
        cin>>l;
        tail->next = new Node(l);
        tail = tail->next;
    }
    head = reverseList(head);
    printList(head);
    cout << endl;
    return 0;
}