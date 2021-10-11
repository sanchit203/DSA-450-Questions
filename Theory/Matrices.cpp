#include<iostream>
#include<stdlib.h>

using namespace std;

struct Matrices{
    int A[30];
    int n;
};

void Set(Matrices *a, int i, int j, int x)
{
    if(i==j && i<=a->n)
    a->A[i-1]=x;
    return;
}

int Get(Matrices a, int i, int j)
{
    if(i<=a.n && j<=a.n)
    {
        if(i==j)
            return a.A[i-1];
        return 0;
    }
    return -1;
}

void display(Matrices a)
{
    for(int i=1; i<= a.n; i++)
    {
        for(int j=1; j<=a.n;j++)
        {
            if(i==j)
                cout<<a.A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }    
}

class DiagonalMatrices
{
    int *A;
    int n;
    public :
    DiagonalMatrices()
    {
        n=2;
        A = new int[2];
    }
    DiagonalMatrices(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~DiagonalMatrices()
    {
        delete []A;
        A=NULL;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void DiagonalMatrices :: Set(int i, int j, int x)
{
    if(i==j && i<=n)
        A[i-1]= x;
}

int DiagonalMatrices :: Get(int i, int j)
{
    if(i<=n && j<=n)
    {
        if(i==j)
            return A[i-1];
        return 0;
    }
    return -1;
}

void DiagonalMatrices :: Display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j)
                cout<<A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

class RowMajLowTriMat
{
    int *A;
    int n;
    public:
    RowMajLowTriMat()
    {
        n=2;
        A = new int[n*(n+1)/2];
    }
    RowMajLowTriMat(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~RowMajLowTriMat()
    {
        delete []A;
        A = NULL;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void RowMajLowTriMat :: Set(int i, int j, int x)
{
    if(i>=j && i<=n)
        A[ (i*(i-1)/2) + j-1 ] = x;
}

int RowMajLowTriMat :: Get(int i, int j)
{
    if(i<=n && j<=n)
    {
        if(i<j)
            return 0;
        return A[((i*(i-1)/2) + j-1)];
    }
    return -1;
}

void RowMajLowTriMat :: Display()
{
    for(int i=1; i<=n; i++)
    {
        for( int j=1; j<=n ;j++)
        {
            if(i<j)
                cout<<"0 ";
            else
                cout<<A[ (i*(i-1)/2) + j-1 ]<<" ";
        }
        cout<<endl;
    }
}

class ColMajLowTriMat
{
    int *A;
    int n;
    public:
    ColMajLowTriMat()
    {
        n=2;
        A = new int[n*(n+1)/2];
    }
    ColMajLowTriMat(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~ColMajLowTriMat()
    {
        delete []A;
        A = NULL;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void ColMajLowTriMat :: Set(int i, int j, int x)
{
    if(i>=j && i<=n)
        A[n*(j-1) - (j-2)*(j-1)/2 + (i-j)] = x;
}

int ColMajLowTriMat :: Get(int i, int j)
{
    if(i<=n && j<=n)
    {
        if(i<j)
            return 0;
        return A[n*(j-1) - (j-2)*(j-1)/2 + (i-j)];
    }
    return -1;
}

void ColMajLowTriMat :: Display()
{
    for(int i=1; i<=n; i++)
    {
        for( int j=1; j<=n ;j++)
        {
            if(i<j)
                cout<<"0 ";
            else
                cout<<A[n*(j-1) - (j-2)*(j-1)/2 + (i-j)]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    system("cls");
    Matrices M = {{2, 3}, 4};
    Set(&M, 3, 3, 8);
    Set(&M, 4, 4, 9);
    cout<< Get(M, 3, 3)<< endl;
    display(M);
    cout<<"Creating class for diagonal matrices program..."<<endl;
    DiagonalMatrices Ob(5);
    Ob.Set(1,1,3);
    Ob.Set(2,2,3);
    Ob.Set(3,3,3);
    Ob.Set(4,4,3);
    Ob.Set(5,5,3);
    cout<<Ob.Get(4,4)<<endl;
    Ob.Display();
    cout<<"Creating Row major lower triangular matrices..."<<endl;
    RowMajLowTriMat Ob2(5);
    Ob2.Set(1,1, 1); Ob2.Set(2,1, 2); Ob2.Set(2,2, 3); Ob2.Set(3,1, 4); Ob2.Set(3,2, 5); Ob2.Set(3,3, 6); Ob2.Set(4,1, 7);
    Ob2.Set(4,2, 8); Ob2.Set(4,3, 9); Ob2.Set(4,4, 9); Ob2.Set(5,1, 1); Ob2.Set(5,2, 2); Ob2.Set(5,3, 3); Ob2.Set(5,4, 4);
    Ob2.Set(5,5, 5);
    cout<<Ob2.Get(3, 3)<<endl;
    Ob2.Display();
    cout<<"Creating Col major lower triangular matrices..."<<endl;
    ColMajLowTriMat Ob3(5);
    Ob3.Set(1,1, 1); Ob3.Set(2,1, 2); Ob3.Set(2,2, 3); Ob3.Set(3,1, 4); Ob3.Set(3,2, 5); Ob3.Set(3,3, 6); Ob3.Set(4,1, 7);
    Ob3.Set(4,2, 8); Ob3.Set(4,3, 9); Ob3.Set(4,4, 9); Ob3.Set(5,1, 1); Ob3.Set(5,2, 2); Ob3.Set(5,3, 3); Ob3.Set(5,4, 4);
    Ob3.Set(5,5, 5);
    cout<<Ob3.Get(3, 3)<<endl;
    Ob3.Display();
    return 0;
}