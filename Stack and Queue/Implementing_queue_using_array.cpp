#include<bits/stdc++.h>
using namespace std;

struct queu{
    int front;
    int rear;
    int size;
    int *p;
};

void push(queu *s)
{
    int x;
    if(s->rear==s->size-1)
    {
        cout<<"Queue overflow!";
        exit(1);
    }
    else
    {
        cout<<"Enter value to be inserted: ";
        cin>>x;
        s->rear++;
        s->p[s->rear]=x;
        return;
    }
}

void pop(queu *s)
{
    if(s->front==s->rear)
    {
        cout<<"Queue underflow!";
        exit(1);
    }
    else
    {
        s->front++;
        cout<<"Popped out value is: "<<s->p[s->front]<<endl;
        return;
    }
}

void display(queu *s)
{
    if(s->front==s->rear)
    {
        cout<<"Queue underflow!";
        exit(1);
    }
    cout<<"Current queue: ";
    for(int i=s->front+1;i<=s->rear;i++)
    {
        cout<<s->p[i]<<' ';
    }
    cout<<endl;
    return;
}

int main()
{
    queu s;
    system("cls");
    int choose;
    cout<<"Enter size of queue: ";
    cin>>s.size;
    s.rear=s.front = -1;
    s.p = new int[s.size];
    label:
    cout<<"Enter 1 to insert, 2 to delete, 3 to display: ";
    cin>>choose;
    switch (choose)
    {
    case 1: push(&s);
            break;
    case 2: pop(&s);
            break;
    case 3: display(&s);
            break;
    }
    cout<<endl<<"If you want to choose again enter 1 otherwise enter 0: ";
    cin>>choose;
    if(choose==1)
    goto label;
    return 0;
}
