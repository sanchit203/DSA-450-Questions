#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    int count=0;
    stack<char> stk;
    for(int i=0;i<s.length();i++)
    {
        if(!stk.empty())
        {
            if(s[i]=='}')
            {
                if(stk.top()=='{')
                stk.pop();
                else
                stk.push(s[i]);
            }
            else
            stk.push(s[i]);
        }
        else
        stk.push(s[i]);
    }
    while(stk.size()>1)
    {
        char a=stk.top();
        stk.pop();
        char b=stk.top();
        stk.pop();
        if(a==b)
        count++;
        else
        count = count+2;
    }
    if(!stk.empty())
    return -1;
    return count;
}

int main()
{
    system("cls");
    cout<<"Enter string(only '{' and '}'): ";
    string a;
    cin>>a;
    cout<<"Minimum no. of bracket reversal needed to make an expression balanced is: ";
    cout<<countRev(a);
    return 0;
}
