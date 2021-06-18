#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

node* middleNode(node* head) 
{
    node *p=head;
    int count =0;
    while(p)
    {
        p=p->next;
        count++;
    }
    p=head;
    for(int i=0;i<count/2;i++)
        p=p->next;
    return p;
}

int main(void)
{
    system("cls");
    cout<<"Enter no. of elements of linked list: ";   
    struct node* head = NULL;
    struct node* temp = NULL;
    int n;
    cin >> n;
    cout<<"Enter elements of linked list: ";
    for(int i=0 ; i<n ; i++)
    {
        int value;
        cin >> value;
        if(i == 0)
        {
            head = new node(value);
            temp = head;
        }
        else
        {
            temp->next = new node(value);
            temp = temp->next;
        }
    }
    node *middle = NULL;
    middle = middleNode(head);
    cout<<"Elements after middle node are: ";
    printList(middle);
    return 0;
}