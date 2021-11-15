#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
class ArrayQueue
{
    int front;
    int rear;
    int size;
    T *q;
    public:
    ArrayQueue(int size)
    {
        front = rear = -1;
        this->size = size;
        q = new T[size];
    }

    ~ArrayQueue()
    {
        delete []q;
        q=NULL;
    }

    void enqueue(T x)
    {
        if(rear == size-1)
        {
            cout<<"Queue overflow"<<endl;
            return;
        }
        q[++rear] = x;
    }

    T dequeue()
    {
        if(front == rear)
        {
            cout<<"Queue underflow"<<endl;
            front = rear = -1;
            return -1;
        }
        return q[++front];
    }

    void Display()
    {
        for(int i=front+1; i<=rear;i++)
        {
            cout<<q[i]<<' ';
        }
        cout<<endl;
    }
};

template<class T>
class CircularQueue
{
    int front;
    int rear;
    int size;
    T *q;
    public:
    CircularQueue(int size)
    {
        front = rear = 0;
        this->size = size;
        q = new T[size];
    }

    ~CircularQueue()
    {
        delete []q;
        q=NULL;
    }
    void enqueue(T x)
    {
        if((rear+1)%size == front)
        {
            cout<<"Queue overflow"<<endl;
            return;
        }
        rear = (rear+1)%size;
        q[rear] = x;
    }

    T dequeue()
    {
        if(front == rear)
        {
            cout<<"Queue underflow"<<endl;
            front = rear = 0;
            return -1;
        }
        front = (front+1)%size;
        return q[front];
    }

    void Display()
    {
        for(int i=(front+1); i!=(rear+1)%size;i=(i+1)%size)
        {
            cout<<q[i]<<' ';
        }
        cout<<endl;
    }
};

struct Node
{
    int data;
    Node *next;
};

class LLQueue{
    Node *f;
    Node *r;

    public:
    LLQueue()
    {
        f = NULL;
        r = NULL;
    }

    void enqueue(int x)
    {
        Node *temp = new Node;
        if(temp==NULL)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        temp->data = x;
        temp->next = NULL;
        if(f == NULL)
            f = r = temp;
        else
        {
            r->next = temp;
            r = temp;
        }
    }

    int dequeue()
    {
        int x=-1;
        if(f==NULL)
        {
            cout<<"Queue underflow"<<endl;
            return x;
        }
        Node *temp = new Node;
        temp = f;
        f = f->next;
        x= temp->data;
        delete temp;
        temp=NULL;
        return x;
    }

    void Display()
    {
        Node *temp = f;
        while(temp)
        {
            cout<<temp->data<<' ';
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    system("cls");
    ArrayQueue<int> Ob(10);
    Ob.enqueue(1);
    Ob.enqueue(2);
    Ob.enqueue(3);
    Ob.Display();
    cout<<Ob.dequeue()<<endl;
    Ob.Display();
    CircularQueue<char> Ob1(3);
    Ob1.enqueue('a');
    Ob1.enqueue('b');
    Ob1.Display();
    cout<<Ob1.dequeue()<<endl;
    Ob1.enqueue('c');
    Ob1.Display();
    Ob.~ArrayQueue();
    Ob1.~CircularQueue();
    LLQueue Ob2;
    Ob2.enqueue(1);
    Ob2.enqueue(2);
    Ob2.Display();
    cout<<Ob2.dequeue()<<endl;
    Ob2.Display();
    return 0;
}