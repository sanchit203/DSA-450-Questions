#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a){
        int i,j,temp=-1;
    for(i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1])
        {
            temp=a[i];
            break;
        }
    }
    if(temp==-1)
    {
        sort(a.begin(),a.end());
        return a;
    }
    for(j=n-1;j>i;j--)
    {
        if(a[j]>a[i])
        {
            a[i]=a[j];
            a[j]=temp;
            break;
        }
    }
    for(i=i+1,j=n-1;j>i;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    return a;
    }
};

int main()
{
    system("cls");
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}