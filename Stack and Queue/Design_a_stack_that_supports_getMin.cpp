#include<bits/stdc++.h>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
stack<int> s;
int main()
{
    system("cls");
    cout<<"Enter size: ";
	int n,a;
	cin>>n;
	while(!isEmpty(s))
    {
	    pop(s);
	}
    cout<<"Enter elements: ";
	while(!isFull(s,n))
    {
		cin>>a;
		push(s,a);
	}
	cout<<"Minimum value of stack: "<<getMin(s)<<endl;
    return 0;
	
}


void push(stack<int>& s, int a){
    s.push(a);
}

bool isFull(stack<int>& s,int n){
    if(s.size()==n)
    return 1;
    return 0;
}

bool isEmpty(stack<int>& s){
    return s.empty();
}

int pop(stack<int>& s){
    int x=s.top();
    s.pop();
    return x;
}

int getMin(stack<int>& s){
    int A[s.size()];
    int n=s.size();
    for(int i=0;i<n;i++)
    {
    A[i]=s.top();
    s.pop();
    }
    int min= A[0];
    for(int i=1;i<n;i++)
    if(min>A[i])
    min=A[i];
    for(int i=n-1;i>=0;i--)
    s.push(A[i]);
    return min;
}