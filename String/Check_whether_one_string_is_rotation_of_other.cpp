#include<bits/stdc++.h>

using namespace std;

int isRotation(string a, string b)
{
    if(a.length()!=b.length())
    {
        return 0;
    }

    string temp = a+a;

    int i,k=0;
    for(int i=0;i<temp.length()-1;i++)
    {
        if(k==b.length()-1)
        {
            return 1;
        }
        if(temp[i]==b[k])
        k++;
        else
        k=0;
    }
    return 0;
}

int main()
{
    system("cls");
    cout<<"Enter string1: ";
    string a,b;
    cin>>a;
    cout<<"Enter string2: ";
    cin>>b;
    isRotation(a,b)? cout<<"String1 is a rotation of String 2." : cout<<"String1 is not a rotation of string2.";
    return 0;
}