#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    bool isPalindrome(Node *head)
    {
        Node *r,*q,*p=head;
        int count=0;
        while(p)
        {
            p=p->next;
            count++;
        }
        p=head;
        if(count%2==0)
        for(int i=0;i<count/2;i++)
        p=p->next;
        else
        for(int i=0;i<(count/2)+1;i++)
        p=p->next;
        r=NULL;
        q=NULL;
        while(p)
        {
            q=p;
            p=p->next;
            q->next=r;
            r=q;
        }
        p=head;
        for(int i=0;i<count/2;i++)
        {
            if(p->data!=q->data)
            return false;
            p=p->next;
            q=q->next;
        }
        return true;
    }
};

int main()
{
    system("cls");
    int i,n,l,firstdata;
    struct Node *head = NULL,  *tail = NULL;
    cout<<"Enter no. of elements of linked list: ";
    cin>>n;
    cout<<"Enter values of linked list: ";
    cin>>firstdata;
    head = new Node(firstdata);
    tail = head;
    for(i=1;i<n;i++)
    {
        cin>>l;
        tail->next = new Node(l);
        tail = tail->next;
    }
    Solution obj;
   	obj.isPalindrome(head)?cout<<"Given linked list is a palindrome." : cout<<"Given linked list is not a palindrome.";
    return 0;
}