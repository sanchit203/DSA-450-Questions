#include<bits/stdc++.h>

using namespace std;

void find (char line[], char txt[])
{
    int i,index,j=0;
    for(int i=0; i<strlen(line);i++)
    {
        index=i;
        if(txt[j]==line[i])
        {
            while (j<strlen(txt)&&i<strlen(line))
            {
                if(txt[j]==line[i])
                {
                    i++;
                    j++;
                }
                else
                break;
            }
            if(j==strlen(txt))
            {
                cout<<"Patter found at index "<<index;
                cout<<endl;
            }
            j=0;
        }
    }
}

int main()
{
    system("cls");
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    find(txt,pat);
    return 0;
}