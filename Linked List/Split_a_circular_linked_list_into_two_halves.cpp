#include<bits/stdc++.h>
#include<stdio.h> 
#include<stdlib.h> 
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
}; 

void splitList(struct Node *head, struct Node **head1_ref,   struct Node **head2_ref);
 struct Node* newNode(int key)
{
    struct Node *temp = new Node(key);
    
    return temp;
}

void printList(struct Node *head)
{
  struct Node *temp = head; 
  if(head != NULL)
  {
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
    printf("\n");
  }
}

int main()
{
    system("cls");
    int n,i,x;
	struct Node *temp,*head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    cout<<"Enter no. of elements circular linked list: ";
	scanf("%d",&n);
    cout<<"Enter values of elements of circular linked list: ";
	scanf("%d",&x);
	head=new Node(x);
	temp=head;
	for(i=0;i<n-1;i++)
    {
	    scanf("%d",&x);
    
	    temp->next=new Node(x);
    
	    temp=temp->next;
    
	}
    
    temp->next=head;
    splitList(head, &head1, &head2);
    cout<<"First half of circular linked list is: ";
    printList(head1);  
    cout<<"Second half of circular linked list is: ";
    printList(head2);  
    return 0;
}

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *r,*p=head;
    int count=0;
    do
    {
        count++;
        p=p->next;
    }while(p!=head);
    p=head;
    if(count%2==1)
    for(int i=0;i<count/2;i++)
    {
        p=p->next;
    }
    else
    for(int i=0;i<(count/2)-1;i++)
    {
        p=p->next;
    }
    r=p->next;
    p->next=head;
    p=r;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=r;
    *head1_ref=head;
    *head2_ref=r;
}