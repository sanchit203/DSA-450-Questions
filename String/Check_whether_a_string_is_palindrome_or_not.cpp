#include<bits/stdc++.h>

using namespace std;

int isPlaindrome(string S)
{
    int i,j,n= S.length();
    for(i=0,j=n-1;i<j;i++,j--)
    if(S[i]!=S[j])
    return 0;
    return 1;
}

int main() 
{
    system("cls");
    string s;
    cout<<"Enter string: ";
   	cin >> s;
   	isPlaindrome(s)? cout<<"String is palindrome." : cout<<"String is not a palindrome.";
    return 0;
}