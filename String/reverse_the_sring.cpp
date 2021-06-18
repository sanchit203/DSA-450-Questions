#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main() {
    system("cls");
	string s;
    cout<<"Enter string: ";
	cin >> s;
	cout <<"Reversed string: "<< reverseWord(s) << endl;
	return 0;
}

string reverseWord(string str){
    reverse(str.begin(),str.end());
    return str;
}