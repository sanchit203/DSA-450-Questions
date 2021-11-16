#include<iostream>
#include<stdlib.h>
#include"Stack.h"

using namespace std;

class BST{
    public:
    node *root;
    BST()
    {
        root= NULL;
    }

    void Insert(int ele)
    {
        node *r, *p;
        r=p=root;
        if(root==NULL)
        {
            root = new node;
            root->lchild = root->rchild = NULL;
            root->x = ele;
            return;
        }
        while(p)
        {
            r=p;
            if(ele<p->x)
                p=p->lchild;
            else if(ele>p->x)
                p=p->rchild;
            else
                return;
        }
        p= new node;
        p->lchild =p->rchild = NULL;
        p->x = ele;
        if(r->x > p->x)
            r->lchild = p;
        else
            r->rchild = p;
    }

    node *RInsert(node *p, int ele)
    {
        if(p==NULL)
        {
            p= new node;
            p->lchild = p->rchild = NULL;
            p->x = ele;
            return p;
        }
        if(ele>p->x)
            p->rchild = RInsert(p->rchild, ele);
        else if(ele<p->x)
            p->lchild = RInsert(p->lchild, ele);
        else
            return NULL;
        return p;
    }

    int search(int ele)
    {
        node *p = root;
        while(p)
        {
            if(p->x>ele)
                p=p->lchild;
            else if(p->x<ele)
                p=p->rchild;
            else
                return 1;
        }
        return 0;
    }

    node *Rsearch(node *p, int ele)
    {
        if(p==NULL)
            return NULL;
        if(p->x == ele)
            return p;
        else if(p->x > ele)
            return Rsearch(p->lchild, ele);
        else
            return Rsearch(p->rchild, ele);
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

    node *InPre(node *p)
    {
        while(p&&p->rchild!=NULL)
            p=p->rchild;
        return p;
    }

    node *InSucc(node *p)
    {
        while(p&&p->lchild!=NULL)
            p=p->lchild;
        return p;
    }

    node *Delete(node *p, int ele)
    {
        node *q;
        if(p==NULL)
            return NULL;
        if(p->lchild == NULL && p->rchild == NULL && p->x == ele)
        {
            if(p==root)
                root = NULL;
            delete p;
            return NULL;
        }

        if(ele< p->x)
            p->lchild = Delete(p->lchild, ele);
        else if(ele > p->x)
            p->rchild = Delete(p->rchild, ele);
        else
        {
            if(height(p->lchild)> height(p->rchild))
            {
                q= InPre(p->lchild);
                p->x = q->x;
                p->lchild = Delete(p->lchild, q->x);
            }
            else
            {
                q= InSucc(p->rchild);
                p->x = q->x;
                p->rchild = Delete(p->rchild, q->x);
            }
        }
        return p;
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

    void Preorder(node *p)
    {
        if(p)
        {
            cout<<p->x<<' ';
            Preorder(p->lchild);
            Preorder(p->rchild);
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

    void CreatePre(int pre[], int n)
    {
        linkedliststack st;
        int i=0;
        node *p, *t;
        root = new node;
        root->x = pre[i++];
        root->lchild = root->rchild = NULL;
        p=root;
        while(i<n)
        {
            if(pre[i]<p->x)
            {
                t= new node;
                t->lchild =t->rchild = NULL;
                t->x = pre[i++];
                p->lchild = t;
                st.push(p);
                p=t;
            }
            else if(pre[i]>p->x)
            {
                if(!st.isEmpty())
                {
                    if(pre[i]<st.to()->x)
                    {
                        t= new node;
                        t->x = pre[i++];
                        t->lchild = t->rchild = NULL;
                        p->rchild = t;
                        p=t;
                    }
                    else
                    {
                        p=st.pop();
                    }
                }
                else
                {
                    t= new node;
                    t->x = pre[i++];
                    t->lchild = t->rchild = NULL;
                    p->rchild = t;
                    p=t;
                }
            }
        }
    }
};

int main()
{
    system("cls");
    BST ob;
    ob.Insert(50);
    ob.Insert(40);
    ob.RInsert(ob.root, 60);
    ob.RInsert(ob.root, 30);
    ob.Insert(45);
    ob.Insert(65);
    ob.Inorder(ob.root);
    cout<<endl;
    ob.Preorder(ob.root);
    cout<<endl;
    cout<<ob.search(65)<<endl;
    int a[] = {50, 40, 30, 45, 60, 65};
    BST ob2;
    ob2.CreatePre(a, 6);
    ob2.Inorder(ob2.root);
    cout<<endl;
    ob2.Preorder(ob2.root);
    return 0;
}