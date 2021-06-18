#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

Node *lasttofront(Node *head)
{
    Node *p,*q;
    p=head;
    while(p->next)
    {
        q=p;
        p=p->next;
    }
    q->next=NULL;
    p->next=head;
    head=p;
    return head;
}

int main() 
{
    system("cls");
    cout<<"Eneter no. elements of linked lsit: ";
	int K;
	cin>>K;
	Node *head = NULL;
    Node *temp = head;
    cout<<"Enter elements of linked list: ";
	for(int i=0;i<K;i++)
    {
	    int data;
	    cin>>data;
	    if(head==NULL)
	    head=temp=new Node(data);
	    else
	    {
	    	temp->next = new Node(data);
	    	temp=temp->next;
	    }
	}
	Node *result  = lasttofront(head);
    cout<<"Elements of linked list after moving last element to first: ";
	print(result);
	cout<<endl;
	return 0;
}