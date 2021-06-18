#include<bits/stdc++.h>

using namespace std;

void printDuplicates(string S)
{
    long long int H, X=0;
    for(int i=0;S[i]!='\0';i++)
    {
        H=1;
        if(S[i]>=65&&S[i]<=90)
        {
            H=H<<(S[i]-65);
        }
        else if(S[i]>=97&&S[i]<=122)
        {
            H=H<<(S[i]-97+26);
        }
        if(H&X)
        {
            cout<<S[i]<<" ";
        }
        else
        {
            X=H|X;
        }
    }
}

int main()
{
    system("cls");
    cout<<"Enter sring: ";
    string S;
    cin>>S;
    cout<<"Duplicates are: ";
    printDuplicates(S);
}