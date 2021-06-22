#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> a,b;
        stack<long long> st;
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(arr[i]>=st.top())
            {
                while(!st.empty()&&arr[i]>=st.top())
                st.pop();
                if(st.empty())
                a.push_back(-1);
                else
                a.push_back(st.top());
            }
            else
            a.push_back(st.top());
            st.push(arr[i]);
        }
        int i=a.size()-1;
        while(i>=0)
        {
            b.push_back(a[i]);
            i--;
        }
        return b;
    }
};

int main()
{
    system("cls");
    cout<<"Enter no. of elements: ";
    int n;
    cin>>n;
    vector<long long> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Solution obj;
    vector <long long> res = obj.nextLargerElement(arr, n);
    cout<<"Next greater element is: ";
    for (long long i : res) cout << i << " ";
    cout<<endl;
	return 0;
}