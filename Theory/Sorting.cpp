#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

void BubbleSort(int A[], int n)
{
    int flag, temp;
    for(int i=0;i<n-1;i++)
    {
        flag = 0;
        for(int j=0;j<n-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j]=A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

void InsertionSort(int A[], int n)
{
    int j,x;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        while(A[j]>x && j>-1)
        {
            A[j+1]= A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void SelectionSort(int A[], int n)
{
    int i,j,k,temp;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j = i;j<n;j++)
            if(A[j]<A[k])
                k=j;
        temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

int partition(int A[], int l, int h)
{
    int temp, pivot = A[l];
    int i=l, j=h;
    do{
        do{++i;}while(A[i]<= pivot);
        do{--j;}while(A[j]> pivot);

        if(i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);

    temp = A[l];
    A[l] = A[j];
    A[j] = temp;

    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1, h);
    }
}

void Merge(int A[], int l, int mid, int h)
{
    int B[h+1];
    int i,j,k;
    i=l;j=mid+1;k=l;
    while(i<=mid&&j<=h)
    {
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(;i<=mid;i++)
        B[k++] = A[i];
    for(;j<=h;j++)
        B[k++] = A[j];
    for(i=l;i<=h;i++)
        A[i] = B[i];
}

void IMergeSort(int A[], int n)
{
    int p, i, l, mid, h;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid = (l+h)/2;
            Merge(A,l,mid, h);
        }
    }
    if(p/2<n)
        Merge(A,0,p/2,n-1);
}

void RMergeSort(int A[], int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

int findmax(int A[], int n)
{
    int max= A[0];
    for(int i=1;i<n;i++)
        if(A[i]>max)
            max = A[i];
    return max;
}

void CountSort(int A[], int n)
{
    int max, i, j;
    max = findmax(A, n);
    int *c = new int[max+1];
    for(i=0;i<max+1;i++)
        c[i]= 0;
    for(i=0;i<n;i++)
        c[A[i]]++;
    i=j=0;
    while(i<max+1)
    {
        if(c[i]>0)
        {
            A[j++] = i;
            c[i]--;
        }
        else
            i++;
    }
}

struct node
{
    int data;
    node *next;
};

node* Insert(node *p, int i)
{
    node *t = new node;
    t->data = i;
    t->next = NULL;
    if(p==NULL)
    {
        p=t;
        return p;
    }
    else
    {
        node *r=p;
        while(p->next!=NULL)
            p=p->next;
        p->next = t;
        return r;
    }
}

void BinSort(int A[], int n)
{
    int max, i,j;
    node **bins;
    max= findmax(A, n);
    bins = new node *[max+1];
    for(i=0;i<max+1;i++)
        bins[i] = NULL;
    for(i=0; i<n;i++)
        bins[A[i]] = Insert(bins[A[i]], A[i]);
    i=j=0;
    while(i<max+1)
    {
        while(bins[i]!=NULL)
        {
            A[j++] = bins[i]->data;
            node *p=bins[i];
            bins[i] = bins[i]->next;
            delete p;
            p=NULL;
        }
        i++;
    }
}

void RadixSort(int A[], int n)
{
    int max, i,j,k, count;
    node **bins;
    max= findmax(A, n);
    bins = new node *[10];
    for(i=0;i<10;i++)
        bins[i] = NULL;
    k=1, count=0;
    for(int i=10;max/i>0;i=i*10)
        count++;
    while(k<=pow(10, count))
    {
        for(i=0; i<n;i++)
            bins[(A[i]/k)%10] = Insert(bins[(A[i]/k)%10], A[i]);
        i=j=0;
        while(i<10)
        {
            while(bins[i]!=NULL)
            {
                A[j++] = bins[i]->data;
                node *p=bins[i];
                bins[i] = bins[i]->next;
                delete p;
                p=NULL;
            }
            i++;
        }
        k=k*10;
    }
}

void ShellSort(int A[], int n)
{
    int gap, i,j, temp;
    for(gap = n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp = A[i];
            j=i-gap;
            while(j>=0 && temp<A[j])
            {
                A[j+gap] = A[j];
                j=j-gap;
            }
            A[j+gap] = temp;
        }
    }
}

void Display(int A[], int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<' ';
    cout<<endl;
}

int main()
{
    system("cls");
    int A[] = {6, 8, 3, 7, 10, 9, INT32_MAX};
    Display(A, 6);
    /* BubbleSort(A, 7);
    Display(A, 6);
    InsertionSort(A, 7);
    Display(A, 6);
    SelectionSort(A, 7);
    Display(A, 6);
    QuickSort(A, 0, 6);
    Display(A, 6);
    IMergeSort(A, 7);
    Display(A, 6);
    RMergeSort(A, 0, 7);
    Display(A, 6);
    CountSort(A, 6);
    Display(A, 6);
    BinSort(A, 6);
    Display(A, 6);
    RadixSort(A, 6);
    Display(A, 6);
    ShellSort(A, 6);
    Display(A, 6); */
    return 0;
}