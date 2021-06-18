#include<bits/stdc++.h>

using namespace std;

int count(string s)
{
    int count0,count1,count_string;
    count0=count1=count_string=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        count0++;
        else
        count1++;
        if(count0==count1)
        {
            count_string++;
            count0=count1=0;
        }
    }
    if(count0!=0||count1!=0)
    return -1;
    return count_string;
}

int main()
{
    system("cls");
    string s;
    cout<<"Enter the binary string: ";
    cin>>s;
    cout<<"Maximum no. of substrings with equal no. of 0s and 1s are: ";
    cout<<count(s);
    return 0;
}