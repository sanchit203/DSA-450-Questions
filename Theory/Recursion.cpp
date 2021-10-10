#include<iostream>

using namespace std;

void tailrec(int n)
{
    if(n>0)
    {
        cout<<n<<' ';
        tailrec(n-1);
    }
    return;
}

void headrec(int n)
{
    if(n>0)
    {
        headrec(n-1);
        cout<<n<<' ';
    }
    return;
}

int staticrec(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return staticrec(n-1) + x;
    }
    return 0;
}

void treerec(int n)
{
    static int x=0;
    if(n>0)
    {
        cout<<n<<' ';
        treerec(n-1);
        treerec(n-1);
    }
    return;
}

void indirectB(int n);

void indirectA(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        indirectB(n-1);
    }
}

void indirectB(int n)
{
    if(n>1)
    {
        cout<<n<<" ";
        indirectA(n/2);
    }
}

int nestedrec(int n)
{
    if(n>0)
    {
        int x;
        x = nestedrec(nestedrec(n/2)-2) + 1;
        return x;
    }
    return 0;
}

int sumrec(int n)
{
    if(n==1)
    {
        return 1;
    }
    return sumrec(n-1) + n;
}

int factrec(int n)
{
    if(n==1)
    {
        return 1;
    }
    return sumrec(n-1) * n;
}

int powerrec(int m, int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        return powerrec(m*m, n/2);
    }
    return m * powerrec(m, (n-1)/2);
}

double taylorrec(int x, int n)
{
    static double p=1, f=1;
    double r;
    if(n==0)
        return 1;
    r= taylorrec(x, n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

double taylorhanorrec(int x, int n)
{
    static double s;
    if(n==0)
        return 1;
    s= 1+x*s/n;
    return taylorhanorrec(x, n-1);
}

int fibrec( int n)
{
    if(n<=1) return n;
    return fibrec(n-2)+ fibrec(n-1);
}

int nCr(int n, int r)
{
    if(n==r || r==0)
    return 1;
    return nCr(n-1, r-1)+ nCr(n-1, r);
}

void TOH(int n, int a, int b, int c)
{
    if(n>0)
    {
        TOH(n-1, a,c,b);
        cout<<a<<" "<<c<<endl;
        TOH(n-1, b, a, c);
    }
}

int main()
{
    system("cls");
    int x,a;
    cout<<"Choose 1 for tail recursion, 2 for static recursion, 3 for head recursion, 4 for tree recursion, 5 for indirect recursion, 6 for nested recursion, 7 for sum of natural numbers, 8 for factorial, 9 for power, 10 for taylor series, 11 for taylor series using horner rule, 12 for fibonacci, 13 for nCr using recursion, 14 for tower of hanoi: ";
    cin>>x;
    switch (x)
    {
    case 1: cout<<"Enter value: ";
            cin>>a;
            tailrec(a);
            break;
    case 2: cout<<"Enter value: ";
            cin>>a;
            cout<<staticrec(a);
            break;
    case 3: cout<<"Enter value: ";
            cin>>a;
            headrec(a);
            break;
    case 4: cout<<"Enter value: ";
            cin>>a;
            treerec(a);
            break;
    case 5: cout<<"Enter value: ";
            cin>>a;
            indirectA(a);
            break;
    case 6: cout<<"Enter value: ";
            cin>>a;
            cout<<nestedrec(a);
            break;
    case 7: cout<<"Enter value: ";
            cin>>a;
            cout<<sumrec(a);
            break;
    case 8: cout<<"Enter value: ";
            cin>>a;
            cout<<factrec(a);
            break;
    case 9: cout<<"Enter value of base: ";
            cin>>a;
            int b; cout<<"Enter value of power: "; cin>>b;
            cout<<powerrec(a,b);
            break;
    case 10:cout<<"Enter value of base: ";
            cin>>a;
            int b; cout<<"Enter value of power: "; cin>>b;
            cout<<taylorrec(a,b);
            break;
    case 11:cout<<"Enter value of base: ";
            cin>>a;
            int b; cout<<"Enter value of power: "; cin>>b;
            cout<<taylorhanorrec(a,b);
            break;
    case 12:cout<<"Enter value: ";
            cin>>a;
            cout<<fibrec(a);
            break;
    case 13:cout<<"Enter value of base: ";
            cin>>a;
            int b; cout<<"Enter value of power: "; cin>>b;
            cout<<nCr(a,b);
            break;
    case 14:cout<<"Enter value of number of discs: ";
            cin>>a;
            TOH(a,1,2,3);
            break;
    default:
        break;
    }
    return 0;
}