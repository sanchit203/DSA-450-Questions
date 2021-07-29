#include<bits/stdc++.h>
using namespace std;

bool sortcol( const vector<int>& v1, const vector<int>& v2 ) 
    {
        return v1[0] < v2[0];
    }
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),sortcol);
        int start = intervals[0][0];
        int end = intervals[0][1];
        int t=0;
        vector<vector<int>> result;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=end)
            {
                end<intervals[i][1] ? end = intervals[i][1] : end= end;
            }
            else{
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                start = intervals[i][0];
                end = intervals[i][1];
                result.push_back(temp);
            }
        }
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        result.push_back(temp);
        return result;
    }
};

int main()
{
    Solution ob;
    vector<vector<int>> intervals, result;
    int n,m, ele;
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
        {
            cin>>ele;
            temp.push_back(ele);
        }
        intervals.push_back(temp);
    }
    result = ob.merge(intervals);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}