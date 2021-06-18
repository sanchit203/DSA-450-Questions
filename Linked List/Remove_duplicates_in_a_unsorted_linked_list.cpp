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
    cout<<"Eneter no. elements of unsorted linked lsit: ";
	int K;
	cin>>K;
	Node *head = NULL;
    Node *temp = head;
    cout<<"Enter elements of unsorted linked list: ";
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
    cout<<"Elements of unsorted linked list after removing duplicated are: ";
	print(result);
	cout<<endl;
	return 0;
}

Node *removeDuplicates(Node *head)
{
    Node *p, *q, *t;
    p=head;
    q=NULL;
    int max=INT_MIN;
    while(p)
    {
        if(p->data > max)
        max=p->data;
        p=p->next;
    }
    p=head;
    int H[max]={0};
    while(p)
    {
        if(H[p->data]==1)
        {
            t=p;
            p=p->next;
            q->next=p;
            delete t;
        }
        else
        {
            H[p->data]=1;
            q=p;
            p=p->next;
        }
    }
    return head;
}