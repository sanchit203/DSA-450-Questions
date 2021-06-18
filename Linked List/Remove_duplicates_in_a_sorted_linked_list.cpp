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

Node* removeDuplicates(Node *root);

int main() 
{
    system("cls");
    cout<<"Eneter no. elements of sorted linked lsit: ";
	int K;
	cin>>K;
	Node *head = NULL;
    Node *temp = head;
    cout<<"Enter elements of sorted linked list: ";
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
	Node *result  = removeDuplicates(head);
    cout<<"Elements of sorted linked list after removing duplicated are: ";
	print(result);
	cout<<endl;
	return 0;
}

Node *removeDuplicates(Node *head)
{
    Node *p,*q,*t;
    q=head;
    p=NULL;
    while(q)
    {
        if(p&&q->data==p->data)
        {
            t=q;
            q=q->next;
            p->next=q;
            delete t;
        }
        else
        {
            p=q;
            q=q->next;
        }
    }
    return head;
}