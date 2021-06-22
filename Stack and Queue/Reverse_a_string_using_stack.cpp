#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    system("cls");
    char str[10000];
    cout<<"Enter string: ";
    cin>>str;
    long long int len=strlen(str);
    char *ch=reverse(str,len);
    cout<<"Reversed string is: "<<ch;
    cout<<endl;
    return 0;
}

char* reverse(char *S, int len)
{
    stack<char> st;
    int i=0;
    while(i<len)
    {
        st.push(S[i]);
        i++;
    }
    i=0;
    while(!st.empty())
    {
        S[i++] = st.top();
        st.pop();
    }
    return S;
}