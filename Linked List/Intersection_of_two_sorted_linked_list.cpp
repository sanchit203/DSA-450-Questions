#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	system("cls");
	int n,m;
    cout<<"Enter no. of elements of linked list1 and linked list 2: ";
	cin>> n >> m;
	cout<<"Enter values of first linked list: ";
	Node* head1 = inputList(n);
    cout<<"Enter values of second list: ";
	Node* head2 = inputList(m);
	
	Node* result = findIntersection(head1, head2);
	cout<<"Intersection of two given linked list is: ";
	printList(result);
	cout<< endl;
	return 0;
}

Node* findIntersection(Node* head1, Node* head2)
{
    Node *p, *q, *third, *r;
    p=head1;
    q=head2;
    third=NULL;
    while(p&&q)
    {
        if(p->data > q->data)
        q=q->next;
        else if(p->data < q->data)
        p=p->next;
        else
        {
            if(third==NULL)
            {
                r=new Node(p->data);
                third=r;
            }
            else
            {
                r->next=new Node(p->data);
                r=r->next;
            }
            p=p->next;
            q=q->next;
        }
    }
    return third;
}