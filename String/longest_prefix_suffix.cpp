#include<bits/stdc++.h>

using namespace std;

int longest(string a)
{
    int n=a.length();
    int t=1;
	int i=0;
	while(i+t<n)
	{
	    while(i<n-1&&i+t<n)
	    {
	        if(a[i]==a[i+t])
	        {
	            i++;
	        }
	        else
	        {
	            i=0;
	            t++;
	            break;
	        }
	    }
	}
	return n-t;
}

int main()
{
    system("cls");
    string a;
    cout<<"Enter string: ";
    cin>>a;
    cout<<"Maximum length of prefix which is also a suffix is: "<<longest(a);
    return 0;
}