#include<bits/stdc++.h>

using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    sort(arr,arr+N);
    int per_max,temp_max=1;
    per_max=1;
    for(int i=1;i<N;i++)
    {
      if(arr[i]==arr[i-1])
      continue;
      if(arr[i]-arr[i-1]==1)
      {
         temp_max++;
         per_max= max(temp_max,per_max);
      }
      else 
      temp_max=1;
    }
    return per_max;
}

int main()
{
    system("cls");
    int N;
    cout<<"\n Enter the no. of elements of array: ";
    cin>>N;
    int A[N];
    cout<<"\n Enter the elements of array: ";
    for(int i=0;i<N;i++)
    cin>>A[i];
    cout<<"\n Largest coinsecutive subsequence possible is: "<<findLongestConseqSubseq(A,N);
    return 0;
}