#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

template<class T>
class arraystack
{
    int size;
    int top;
    T *a;
    public:
    arraystack()
    {
        size = 10;
        top = -1;
        a = new T[size];
    }
    arraystack(int size)
    {
        this->size = size;
        top = -1;
        a = new T[size];
    }

    void display()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        for(int i=top;i>=0;i--)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    
    void push(T ele)
    {
        if(top == size-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        a[++top] = ele;
    }

    T pop()
    {
        if(top== -1)
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return a[top--];
    }
    T peek(int index)
    {
        if(top-index+1<0)
        {
            cout<<"Invalid index"<<endl;
            return -1;
        }
        return a[top-index+1];
    }

    T Top()
    {
        return a[top];
    }

    int isEmpty()
    {
        return top==-1;
    }
    int isFull()
    {
        return top==size-1;
    }
};

void paranthersismatch(const char *e)
{
    arraystack<char> st(strlen(e));
    for(int i=0;e[i]!='\0';i++)
    {
        if(e[i]=='(')
            st.push(e[i]);
        else if(e[i]==')')
        {
            if(st.isEmpty())
            {
                cout<<"Not balanced"<<endl;
                return;
            }
            else
                st.pop();
        }
    }
    if(st.isEmpty())
    {
        cout<<"Balanced"<<endl;
        return;
    }
    cout<<"Not Balanced"<<endl;
    return;
}

int isOperand(char e)
{
    if(e=='+'||e=='-'||e=='*'||e=='/'||e=='('||e==')'||e=='^')
        return 0;
    else
        return 1;
}

int OutStackPre(char e)
{
    if(e=='+'||e=='-')
        return 1;
    else if(e=='*'||e=='/')
        return 3;
    else if(e=='^')
        return 6;
    else if(e=='(')
        return 7;
    else if(e==')')
        return 0;
    return -1;
}

int InStackPre(char e)
{
    if(e=='+'||e=='-')
        return 2;
    else if(e=='*'||e=='/')
        return 4;
    else if(e=='^')
        return 5;
    else if(e=='(')
        return 0;
    return -1;
}

char* InftoPost(const char *e)
{
    arraystack<char> st(strlen(e));
    char *pos = new char[strlen(e)+1];
    int i=0, j=0;
    while(e[i]!='\0')
    {
        if(isOperand(e[i]))
            pos[j++] = e[i++];
        else
        {
            if(st.isEmpty())
                st.push(e[i++]);
            else
            {
                if(InStackPre(st.Top())<OutStackPre(e[i]))
                    st.push(e[i++]);
                else if(InStackPre(st.Top())>OutStackPre(e[i]))
                    pos[j++]= st.pop();
                else
                {
                    st.pop();
                    i++;
                }
            }
        }
    }
    while(!st.isEmpty())
        pos[j++]=st.pop();
    pos[j]='\0';
    return pos;
}

int EvaluatePost(const char *e)
{
    arraystack<int> st(strlen(e));
    int i, x1, x2, r;
    for(i=0; e[i]!='\0';i++)
    {
        if(isOperand(e[i]))
            st.push(e[i] - '0');
        else
        {
            x2 = st.pop();
            x1 = st.pop();
            switch(e[i])
            {
                case '+' :  r = x1 + x2;
                            st.push(r);
                            break;
                case '-' :  r = x1 - x2;
                            st.push(r);
                            break;
                case '*' :  r = x1 * x2;
                            st.push(r);
                            break;
                case '/' :  r = x1 / x2;
                            st.push(r);
                            break;
            }
        }
    }

    return st.pop();
}

struct element{
    int data;
    element *next;
};

class linkedliststack
{
    element *top;
    public:
    linkedliststack()
    {
        top = NULL;
    }
    
    void push(int data)
    {
        element *temp = new element;
        if(temp==NULL)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        temp->data = data;
        temp->next = top;
        top= temp;
    }

    void display()
    {
        element *t = top;
        while(t)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    int pop()
    {
        if(top==NULL)
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        element *temp = top;
        top =top->next;
        int x = temp->data;
        delete temp;
        temp= NULL;
        return x;
    }
};



int main()
{
    system("cls");
    arraystack<int> ob(5);
    ob.push(1);
    ob.push(2);
    ob.push(3);
    ob.push(4);
    ob.display();
    cout<<ob.pop()<<endl;
    ob.display();
    cout<<ob.isFull()<<endl;
    cout<<ob.peek(2)<<endl;
    linkedliststack o;
    o.push(5);
    o.push(4);
    o.push(3);
    o.push(2);
    o.push(1);
    o.display();
    o.pop();
    o.display();
    const char *e="((a+b)*(c/d))";
    paranthersismatch(e);

    const char *f = "((a+b)*c)-d^e^f";
    cout << InftoPost(f)<<endl;
    const char *res = "35*62/+4-";
    cout<<EvaluatePost(res)<<endl;
    return 0;
}