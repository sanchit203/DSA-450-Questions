//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) 
{
    int i,j,k,z,m=0;
    i=j=k=0;
    while(i<A.length()&&j<B.size())
    {
        z=i;
        k=0;
        if(A[i]==B[j][k])
        {
            m=0;
            while(k<B[j].length()&&i<A.length())
            {
                if(A[i]==B[j][k])
                {
                    i++;
                    k++;
                }
                else
                break;
            }
            if(k==B[j].length())
            {
                z=i;
            }
            else i=z;
        }
        else
        j++;
        if(m==0&&j==B.size())
        {
            m=1;
            j=0;
        }
    }
    if(i==A.length())
    return 1;
    return 0;
    //code here
}