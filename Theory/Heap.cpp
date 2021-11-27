#include<iostream>
#include<stdlib.h>

using namespace std;

class Heap{
    int n;
    int size;
    int *a;
    public:

    Heap(int x)
    {
        size = x+1;
        a = new int[size];
        n=0;
        a[0] = 0;
        for(int i=1;i<size;i++)
            cin>>a[i];
    }

    void insert()
    {
        int i=n+1;
        int x=a[i];
        while(i>1 && x>a[i/2])
        {
            a[i]=a[i/2];
            i=i/2;
        }
        a[i] = x;
        n++;
        return;
    }

    void Create()
    {
        for(int i=1;i<size;i++)
            insert();
    }

    int Delete()
    {
        int x= a[1];
        int temp,j,i=1;
        j=2*i;
        a[i] = a[n];
        while(j<n)
        {
            if(a[j]<a[j+1])
                j=j+1;
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i=j;
                j=2*i;
            }
            else
            {
                break;
            }
        }
        n--;
        return x;
    }

    void HeapSort()
    {
        int x;
        if(n<size-1)
        for(int i=n;i<size;i++)
            insert();
        while(n>0)
        {   
            x = Delete();
            a[n+1] = x;
        }
    }

    void DisplayHeap()
    {
        cout<<endl;
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
    }

    void DisplayArray()
    {
        cout<<endl;
        for(int i=1;i<size;i++)
            cout<<a[i]<<' ';
    }
};

int main()
{
    system("cls");
    Heap Ob(7);
    Ob.DisplayArray();
    Ob.DisplayHeap();
    Ob.Create();
    Ob.DisplayArray();
    Ob.DisplayHeap();
    Ob.HeapSort();
    Ob.DisplayArray();
    Ob.DisplayHeap();
    return 0;
}