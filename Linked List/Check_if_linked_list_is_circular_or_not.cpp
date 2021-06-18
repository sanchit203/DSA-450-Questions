#include<bits/stdc++.h>
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

bool isCircular(Node *head);

int main()
{
    system("cls");
    int i,n,l,k;
    cout<<"Enter no. of elements of linked list: ";
    cin>>n;
    cout<<"Enter 1 if you wnat to make it a circular otherwise enter 0: ";
    cin>>k;
	Node *head=NULL, *tail = NULL;
	int x;
    cout<<"Enter values of linked list: ";
	cin >> x;
	head = new Node(x);
	tail = head;
	for(int i=0;i<n-1;i++)
	{
	    cin>>x;
	    tail -> next = new Node(x);
	    tail = tail -> next;
	}
    if (k==1 && n >= 1)
          tail->next = head;
    isCircular(head)? cout<<"Linked list is circular." : cout<<"Linked list is not circular.";
    return 0;
}

bool isCircular(Node *head)
{
   Node *p=head;
    while(p)
    {
        p=p->next;
        if(p==head)
        return true;
    }
    return false;
}
