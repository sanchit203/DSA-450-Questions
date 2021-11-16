#include<iostream>
#include<stdlib.h>
#include"Stack.h"

using namespace std;

class Tree
{
    public:
    node *root;
    Tree()
    {
        root = NULL;
    }

    void Create()
    {
        int x;
        cout<<"Enter value of root node: ";
        cin>>x;
        node *p;
        p = new node;
        p->x = x;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        LLQueue q;
        q.enqueue(p);
        while(!q.isEmpty())
        {
            p=q.dequeue();
            cout<<"Enter the value of left child, if there is not any left child enter -1: ";
            cin>>x;
            if(x!=-1)
            {
                node *temp;
                temp = new node;
                temp->x = x;
                temp->lchild=NULL;
                temp->rchild=NULL;
                p->lchild = temp;
                q.enqueue(temp);
            }
            cout<<"Enter the value of right child, if there is not any right child eneter -1: ";
            cin>>x;
            if(x!=-1)
            {
                node *temp;
                temp = new node;
                temp->x = x;
                temp->lchild=NULL;
                temp->rchild=NULL;
                p->rchild = temp;
                q.enqueue(temp);
            }
        }
    }

    void Preorder(node *p)
    {
        if(p)
        {
            cout<<p->x<<' ';
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }

    void Inorder(node *p)
    {
        if(p)
        {
            Inorder(p->lchild);
            cout<<p->x<<' ';
            Inorder(p->rchild);
        }
    }

    void Postorder(node *p)
    {
        if(p)
        {
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout<<p->x<<' ';
        }
    }

    void Levelorder()
    {
        node *p;
        cout<<root->x<<' ';
        LLQueue q;
        q.enqueue(root);
        while(!q.isEmpty())
        {
            p= q.dequeue();
            if(p->lchild)
            {
                cout<<p->lchild->x<<' ';
                q.enqueue(p->lchild);
            }
            if(p->rchild)
            {
                cout<<p->rchild->x<<' ';
                q.enqueue(p->rchild);
            }
        }
    }

    void Ipreorder()
    {
        node *t = root;
        linkedliststack st;
        while(t!=NULL || !st.isEmpty())
        {
            if(t!=NULL)
            {
                cout<<t->x<<' ';
                st.push(t);
                t=t->lchild;
            }
            else
            {
                t = st.pop();
                t=t->rchild;
            }
        }
    }

    void Iinorder()
    {
        node *t = root;
        linkedliststack st;
        while(t!=NULL || !st.isEmpty())
        {
            if(t!=NULL)
            {
                st.push(t);
                t=t->lchild;
            }
            else
            {
                t = st.pop();
                cout<<t->x<<' ';
                t=t->rchild;
            }
        }
    }

    int count(node *p)
    {
        int x,y;
        if(p!=NULL)
        {
            x= count(p->lchild);
            y= count(p->rchild);
            return x+y+1;
        }
        return 0;
    }

    int strictcount(node *p)
    {
        int x,y;
        if(p!=NULL)
        {
            x= strictcount(p->lchild);
            y= strictcount(p->rchild);
            if(p->lchild&&p->rchild)
                return x+y+1;
            else
                return x+y;
        }
        return 0;
    }

    int sum(node *p)
    {
        int x,y;
        if(p!=NULL)
        {
            x = sum(p->lchild);
            y = sum(p->rchild);
            return x+y+p->x;
        }
        return 0;
    }

    int height(node *p)
    {
        int x,y;
        if(p!=NULL)
        {
            x= height(p->lchild);
            y= height(p->rchild);
            if(x>y)
                return x+1;
            else
                return y+1;
        }
        return 0;
    }
};

int main()
{
    system("cls");
    Tree ob;
    ob.Create();
    ob.Preorder(ob.root);
    cout<<endl;
    ob.Postorder(ob.root);
    cout<<endl;
    ob.Inorder(ob.root);
    cout<<endl;
    ob.Levelorder();
    cout<<endl;
    ob.Ipreorder();
    cout<<endl;
    ob.Iinorder();
    cout<<endl;
    cout<<ob.count(ob.root)<<endl;
    cout<<ob.strictcount(ob.root)<<endl;
    cout<<ob.sum(ob.root)<<endl;
    cout<<ob.height(ob.root)<<endl;
    return 0;
}