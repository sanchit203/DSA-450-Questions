// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        Node *p, *q;
        p=head;
        q=head;
        while(p)
        {
            q=q->next;
            p=p->next;
            if(p)
            {
                p=p->next;
                if(q==p)
                return true;
            }
        }
        return false;
    }
};

int main()
{
    system("cls");
    int n, num;
    cout<<"Enter no. of elements of linked list: ";
    cin>>n;
    Node *head, *tail;
    cout<<"Enter value of elements: ";
    cin>> num;
    head = tail = new Node(num);
    for(int i=0 ; i<n-1 ; i++)
    {
        cin>> num;
        tail->next = new Node(num);
        tail = tail->next;
    }
    cout<<"Enter value of position(must be <"<<n<<") where you want to make loop: ";
    int pos;
    cin>> pos;
    loopHere(head,tail,pos);
    Solution ob;
    if(ob.detectLoop(head) )
        cout<< "Loop is present in linked list.";
    else
        cout<< "There is no loop in linked list.";
	return 0;
}