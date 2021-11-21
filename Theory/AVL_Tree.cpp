#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
    node *lchild;
    int data;
    int height;
    node *rchild;
};

class AVL{
    public:
    node *root;
    AVL()
    {
        root = NULL;
    }

    int nodeheight(node *p)
    {
        int hl,hr;
        hl = p&& p->lchild?p->lchild->height : 0;
        hr = p&& p->rchild?p->rchild->height : 0;

        return  hl>hr?hl+1:hr+1;
    }

    int BalanceFactor(node *p)
    {
        int hl,hr;
        hl = p&& p->lchild?p->lchild->height : 0;
        hr = p&& p->rchild?p->rchild->height : 0;

        return hl-hr;
    }

    node *LLRotation(node *p)
    {
        node *pl= p->lchild;
        node *plr = pl->rchild;

        pl->rchild = p;
        p->lchild = plr;
        p->height = nodeheight(p);
        pl->height = nodeheight(pl);

        if(root = p)
            root = pl;
        return pl;
    }

    node *RRRotation(node *p)
    {
        node *pr= p->rchild;
        node *prl = pr->lchild;

        pr->lchild = p;
        p->rchild = prl;
        p->height = nodeheight(p);
        pr->height = nodeheight(pr);

        if(root = p)
            root = pr;
        return pr;
    }

    node *LRRotation(node *p)
    {
        node *pl = p->lchild;
        node *plr = pl->rchild;

        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;

        plr->lchild = pl;
        plr->rchild = p;

        pl->height = nodeheight(pl);
        p->height = nodeheight(p);
        plr->height = nodeheight(plr);

        if(root == p)
            root = plr;
        return plr;
    }

    node *RLRotation(node *p)
    {
        node *pr = p->rchild;
        node *prl = pr->lchild;

        pr->lchild = prl->rchild;
        p->rchild = prl->lchild;

        prl->lchild = p;
        prl->rchild = pr;

        pr->height = nodeheight(pr);
        p->height = nodeheight(p);
        prl->height = nodeheight (prl);

        if(root = p)
            root = prl;
        return prl;
    }
    
    node *RInsert(node *p, int ele)
    {
        if(p==NULL)
        {
            p= new node;
            p->lchild = p->rchild = NULL;
            p->data = ele;
            p->height = 1;
            return p;
        }
        if(ele>p->data)
            p->rchild = RInsert(p->rchild, ele);
        else if(ele<p->data  )
            p->lchild = RInsert(p->lchild, ele);
        else
            return NULL;
        
        p->height = nodeheight(p);

        if(BalanceFactor(p)==2 && BalanceFactor(p->lchild) == 1)
            return LLRotation(p);
        else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild) == -1)
            return LRRotation(p);
        else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild) == -1)
            return RRRotation(p);
        else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild) == 1)
            return RLRotation(p);
        return p;
    }

    void Inorder(node *p)
    {
        if(p)
        {
            Inorder(p->lchild);
            cout<<p->data<<' ';
            Inorder(p->rchild);
        }
    }

    void Preorder(node *p)
    {
        if(p)
        {
            cout<<p->data<<' ';
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
            cout<<p->data<<' ';
        }
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
        if(p->lchild == NULL && p->rchild == NULL && p->data == ele)
        {
            if(p==root)
                root = NULL;
            delete p;
            return NULL;
        }

        if(ele< p->data)
            p->lchild = Delete(p->lchild, ele);
        else if(ele > p->data)
            p->rchild = Delete(p->rchild, ele);
        else
        {
            if(height(p->lchild)> height(p->rchild))
            {
                q= InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }
            else
            {
                q= InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }

        p->height = nodeheight(p);

        if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)>=0)
            return LLRotation(p);
        else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
            return LRRotation(p);
        else if(BalanceFactor(p)==-2&& BalanceFactor(p->rchild)==-1)
            return RRRotation(p);
        else if(BalanceFactor(p)== -2 && BalanceFactor(p->rchild)<=0)
            return RLRotation(p);
        return p;
    }
};

int main()
{
    system("cls");
    AVL ob;
    ob.root = ob.RInsert(ob.root, 3);
    ob.RInsert(ob.root, 2);
    ob.RInsert(ob.root, 1);
    ob.Preorder(ob.root);
    cout<<endl;
    ob.Inorder(ob.root);
    cout<<endl;
    ob.Postorder(ob.root);
    cout<<endl<<endl;
    AVL ob1;
    ob1.root = ob1.RInsert(ob1.root, 1);
    ob1.RInsert(ob1.root, 2);
    ob1.RInsert(ob1.root, 3);
    ob1.Preorder(ob1.root);
    cout<<endl;
    ob1.Inorder(ob1.root);
    cout<<endl;
    ob1.Postorder(ob1.root);
    cout<<endl<<endl;
    AVL ob2;
    ob2.root = ob2.RInsert(ob2.root, 50);
    ob2.RInsert(ob2.root, 40);
    ob2.RInsert(ob2.root, 60);
    ob2.RInsert(ob2.root, 30);
    ob2.RInsert(ob2.root, 45);
    ob2.RInsert(ob2.root, 47);
    ob2.Preorder(ob2.root);
    cout<<endl;
    ob2.Inorder(ob2.root);
    cout<<endl;
    ob2.Postorder(ob2.root);
    cout<<endl<<endl;
    AVL ob3;
    ob3.root = ob3.RInsert(ob3.root, 50);
    ob3.RInsert(ob3.root, 40);
    ob3.RInsert(ob3.root, 60);
    ob3.RInsert(ob3.root, 55);
    ob3.RInsert(ob3.root, 65);
    ob3.RInsert(ob3.root, 53);
    ob3.Preorder(ob3.root);
    cout<<endl;
    ob3.Inorder(ob3.root);
    cout<<endl;
    ob3.Postorder(ob3.root);
    cout<<endl;
    ob3.Delete(ob3.root, 65);
    ob3.Preorder(ob3.root);
    cout<<endl;
    ob3.Inorder(ob3.root);
    cout<<endl;
    ob3.Postorder(ob3.root);
    cout<<endl;
    ob3.Delete(ob3.root, 60);
    ob3.Preorder(ob3.root);
    cout<<endl;
    ob3.Inorder(ob3.root);
    cout<<endl;
    ob3.Postorder(ob3.root);
    cout<<endl;
    return 0;
}