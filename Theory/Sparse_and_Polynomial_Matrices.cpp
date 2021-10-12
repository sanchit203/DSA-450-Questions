#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct Element
{
    int i; //Value of row
    int j; //Value of col
    int x; //Element
};

class Sparse
{
    int m; //No. of rows
    int n; //No. of cols
    int num; // No. of elements
    Element *M;
    public :
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        M = new Element[num];
    }
    ~Sparse()
    {
        delete []M;
    }
    void Create()
    {
        cout<<"Enter all the elements of sparse matrix in form of first row number than column number than value"<<endl;
        for(int t=0;t<num;t++)
        {
            cin>>M[t].i>>M[t].j>>M[t].x;
        }
    }
    void display()
    {
        int k=0;
        for(int a=1;a<=m;a++)
        {
            for(int b=1;b<=n;b++)
            {
                if(M[k].i == a && M[k].j == b)
                    cout<<M[k++].x<<" ";
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
    }
    
    Sparse* Add(Sparse a)
    {
        if(m!= a.m || n!=a.n)
            return NULL;
        Sparse *res = new Sparse(m , n, num + a.num);
        int p,q,r;
        p=q=r=0;
        while(p<num && q<a.num)
        {
            if(M[p].i<a.M[q].i)
                res->M[r++] = M[p++];
            else if(M[p].i > a.M[q].i)
                res->M[r++] = a.M[q++];
            else
            {
                if(M[p].j<a.M[q].j)
                    res->M[r++] = M[p++];
                else if(M[p].j > a.M[q].j)
                    res->M[r++] = a.M[q++];
                else
                {
                    res->M[r].i=M[p].i;
                    res->M[r].j = M[p].j;
                    res->M[r++].x = M[p++].x + a.M[q++].x;
                }
            }
        }
        for(;p<num;p++) res->M[r++] = M[p];
        for(;q<a.num;q++) res->M[r++] = a.M[q];
        res->num = r;
        return res;
    }
};

struct Poly{
    int coeff;
    int pow;
};

class Polynomial
{
    int n;
    Poly *p;
    public:
    Polynomial()
    {
        n=2;
        p= new Poly[2];
    }
    Polynomial(int n)
    {
        this->n = n;
        p = new Poly[n];
    }
    ~Polynomial()
    {
        delete [] p;
        p=NULL;
    }

    void create()
    {
        cout<<"Enter coeffecient and than power.."<<endl;
        for(int i=0;i<n;i++)
            cin>>p[i].coeff>>p[i].pow;
        return;
    }

    void Display()
    {
        cout<<"Polynomial: ";
        for(int i=0;i<n;i++)
        {
            cout<<p[i].coeff<<'x'<<p[i].pow;
            if(i!=n-1)
                cout<<" + ";
        }
        cout<<endl;
    }

    int evaluate(int x)
    {
        int sum =0;
        for(int i=0;i<n;i++)
        {
            sum = sum + p[i].coeff * pow(x, p[i].pow);
        }
        return sum;
    }

    Polynomial *addpoly(Polynomial a)
    {
        Polynomial *res = new Polynomial(n + a.n);
        int i,j,k = 0;
        i=j=k;
        while(i<n && j<a.n)
        {
            if(p[i].pow > a.p[j].pow)
                res->p[k++] = p[i++];
            else if(p[i].pow < a.p[j].pow)
                res->p[k++] = a.p[j++];
            else{
                res->p[k]= p[i];
                res->p[k++].coeff = p[i++].coeff + a.p[j++].coeff;
            }
        }

        for(;j<a.n;j++)
            res->p[k++] = a.p[j];
        for(;i<n;i++)
            res->p[k++] = p[i];
        
        res->n = k;
        return res;
    }
};

int main()
{
    system("cls");
    cout<<"Creating first sparse matrix..."<<endl;
    Sparse Ob(5, 5, 3);
    Ob.Create();
    Ob.display();
    cout<<"Creating second sparse matrix..."<<endl;
    Sparse Ob2(5, 5, 3);
    Ob2.Create();
    Ob2.display();
    Sparse *a = Ob.Add(Ob2);
    cout<<"Adding both the matrix..."<<endl;
    a->display();
    delete a;
    a= NULL;

    Polynomial f(2);
    f.create();
    f.Display();
    cout<<f.evaluate(2)<<endl;
    Polynomial g(3);
    g.create();
    g.Display();
    cout<<g.evaluate(2)<<endl;
    Polynomial *h = f.addpoly(g);
    h->Display();
    cout<<h->evaluate(2)<<endl;
    delete h;
    h=NULL;
    return 0;
}