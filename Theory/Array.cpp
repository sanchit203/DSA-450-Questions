#include<iostream>
#include<stdlib.h>

using namespace std;

struct Array
{
    int size;
    int len;
    int A[20];
};

void insert(Array *a, int x)
{
    if(a ->len < a->size)
    {
        a->A[a->len ++] = x;
    }
    else
        cout<<"Array is full";
}

void insertat(Array *a, int x, int ele)
{
     if(a ->len < a->size)
    {
        for(int i=a->len;i>x;i--)
        a->A[i]=a->A[i-1];
        a->A[x]= ele;
        a->len++;
    }
    else
        cout<<"Array is full";
}

int Delete(Array *a)
{
    if(a->len>=1)
    {
        a->len--;
        return a->A[a->len];
    }
    cout<<"Array is empty";
    return -1;
}

int Deleteat(Array *a, int x)
{
    if(a->len>=1 && x<a->len)
    {
        int t=a->A[x];
        for(int i=x; i<a->len;i++)
        a->A[i]=a->A[i+1];
        a->len--;
        return t;
    }
    return -1;
}

void linearsearch(Array *a, int x)
{
    int i,j;
    for(i=0;i<a->len;i++)
    {
        if(a->A[i]==x)
        {
            cout<<"Element found at index "<<i<<endl;
            break;
        }
    }
    if(i<a->len)
    {
        for(j = i ; j>0 ; j--)
        a->A[j] = a->A[j-1];
        a->A[0] = x;
        return;
    }
    cout<<"Element not found"<<endl;
}

void binarysearch(Array a, int x)
{
    int l=0, h=a.len-1, mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(a.A[mid]==x)
        {
            cout<<"Element found at index "<<mid<<endl;
            return;
        }
        else if(a.A[mid]<x)
        {
            l=mid+1;
        }
        else
            h=mid-1;
    }
}

int Get(Array a, int x)
{
    if(x>=0 && x<a.len)
        return a.A[x];
    return -1;
}

void set(Array *a, int x, int ele)
{
    if(x>=0 && x<a->len)
        a->A[x]=ele;
}

int Min(Array a)
{
    int min = a.A[0];
    for(int i=1;i<a.len;i++)
        if(min>a.A[i])
            min = a.A[i];
    return min;
}

int Max(Array a)
{
    int max = a.A[0];
    for(int i=1;i<a.len;i++)
        if(max<a.A[i])
            max = a.A[i];
    return max;
}

int Sum(Array a)
{
    int sum = 0;
    for(int i=0;i<a.len;i++)
        sum = sum + a.A[i];
    return sum;
}

void reverse(Array *a)
{
    int i, j, t;
    for(i=0, j=a->len-1;i<j;i++,j--)
    {
        t=a->A[i];
        a->A[i]=a->A[j];
        a->A[j]=t;
    }
}

void checksort(Array a)
{
    for(int i=0; i<a.len-1;i++)
    {
        if(a.A[i]>a.A[i+1])
        {
            cout<<"Array is not sorted"<<endl;
            return;
        }
    }
    cout<<"Array is sorted"<<endl;
}

Array * merge(Array a, Array b)
{
    int i,j,k=0;
    i=j=k;
    Array *c = new Array;
    while(i<a.len&&j<b.len)
    {
        if(a.A[i]<b.A[j])
        {
            c->A[k++] = a.A[i];
            i++;
        }
        else if(a.A[i]>b.A[j])
        {
            c->A[k++] = b.A[j];
            j++;
        }
        else
        {
            c->A[k++] = a.A[i];
            c->A[k++] = b.A[j];
            i++;
            j++;
        }
    }
    while(i<a.len)
    {
        c->A[k++] = a.A[i];
        i++;
    }
    while(j<b.len)
    {
        c->A[k++] = b.A[j];
        j++;
    }
    c->len = k;
    return c;
}

void display(Array a)
{
    cout<<"Updated array: ";
    for(int i=0; i<a.len;i++)
    cout<<a.A[i]<<" ";
    cout<<endl;
}

int main()
{
    system("cls");
    Array arr = {20, 5, {10 , 5 , 2 , 1 , 4}};
    display(arr);
    insert(&arr , 10);
    display(arr);
    insertat(&arr, 2, 10);
    display(arr);
    cout<<Delete(&arr)<<" is deleted from array"<<endl;
    display(arr);
    cout<<Deleteat(&arr, 1)<<" is deleted from array"<<endl;
    display(arr);
    linearsearch(&arr, 4);
    display(arr);
    cout<<"For binary search array must be sorted so creating a array ..."<<endl;
    Array aray ={20, 12, {2, 5 , 6 , 8 , 9 , 10 ,11 ,12 ,15 ,19 ,28 ,35}};
    display(aray);
    binarysearch(aray, 19);
    cout<<"Element is "<<Get(aray, 9)<<endl;
    set(&aray, 9, 25);
    display(aray);
    display(arr);
    cout<<"Minimum element is "<<Min(arr)<<endl;
    cout<<"Maximum element is "<<Max(arr)<<endl;
    cout<<"Sum of all element is "<<Sum(arr)<<endl;
    display(arr);
    reverse(&arr);
    display(arr);
    checksort(aray);
    checksort(arr);
    Array *a = merge(arr, aray);
    a->size = 20;
    display(*a);
    delete a;
    a= NULL;
    return 0;
}