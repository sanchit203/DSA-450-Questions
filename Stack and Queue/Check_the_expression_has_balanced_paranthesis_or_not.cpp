#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool ispar(string x)
    {
        stack <char> s;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='{'||x[i]=='['||x[i]=='(')
            {
                s.push(x[i]);
            }
            else
            {
                if(x[i]=='}')
                {
                    if(!s.empty()&&s.top()=='{')
                    s.pop();
                    else
                    return false;
                }
                if(x[i]==']')
                {
                    if(!s.empty()&&s.top()=='[')
                    s.pop();
                    else
                    return false;
                }
                if(x[i]==')')
                {
                    if(!s.empty()&&s.top()=='(')
                    s.pop();
                    else
                    return false;
                }
            }
        }
        if(s.empty())
        return true;
        else
        return false;
    }

};

int main()
{
    system("cls");
    cout<<"Enter the string containing parenthisis: ";
    string a;
    cin>>a;
    Solution obj;
    if(obj.ispar(a))
     cout<<"balanced"<<endl;
    else
     cout<<"not balanced"<<endl;
}