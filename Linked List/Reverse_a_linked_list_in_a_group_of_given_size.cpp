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

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        struct node *p, *q, *r, *tail, *head2;
        int z,count=0;
        z=0;
        tail=NULL;
    p=head;
    q=NULL;
    r=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        q->next=r;
        r=q;
        count++;
        if(count==k)
        {
            z++;
            if(z==1)
            {
                tail=head;
                head=q;
            }
            else
            {
                tail->next=q;
                tail=head2;
            }
            count=0;
            q=r=NULL;
            head2=p;
        }
    }
    if(z==0)
    {
        head=q;
        return head;
    }
    tail->next=q;
    return head;
    }
};

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
    cout<<"Enter the value of k: ";
    int k;
    cin>>k;
    cout<<"Reversed linked list is: ";
    Solution ob;
    head = ob.reverse(head, k);
    printList(head);
    return(0);
}