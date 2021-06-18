#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n)
{
    if(n==1)
        return "1";
    string str1 = countAndSay(n-1);
    int count =1;
    string str2;
    for(int i=0; i<str1.length();i++)
    {
        if(str1[i+1]==str1[i])
            count++;
        else
        {
            str2.push_back(count+48);
            str2.push_back(str1[i]);
            count=1;
        }
    }
    return str2;
}

int main()
{
    system("cls");
    cout<<"Enter the position you want to get for count and say(or look and say) sequence: ";
    int n;
    cin>>n;
    cout<<countAndSay(n);
    return 0;
}