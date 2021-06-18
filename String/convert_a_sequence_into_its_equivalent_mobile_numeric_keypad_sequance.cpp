#include<bits/stdc++.h>
using namespace std;

vector<string> z ={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};

string mobile(string a)
{
    string mob;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==' ')
        mob.push_back('0');
        else
        mob.append(z[a[i]-65]);
    }
    return mob;
}

int main()
{
    system("cls");
    string a;
    cout<<"Enter string(only capital letters): ";
    getline(cin,a);
    cout<<mobile(a);
    return 0;
}