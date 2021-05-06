// Question: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// O(n^2) Solution-1: https://practice.geeksforgeeks.org/viewSol.php?subId=62e37d5d5cc9bb8ce5f8c203a47c824a&pid=701428&user=amanguptarkg6
// O(nlogn) Solution-2: https://practice.geeksforgeeks.org/viewSol.php?subId=a685cae856ab378ec269e2cd9e72e39c&pid=701428&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////
///////////////////////     SOLUTION - 1 | DP O(n^2)
//////////////////////////////////////////////////////////////////////////
int longestSubsequence(int n, int a[]){
   int dp[n] = {0};
   int answer = 0;
   
   for(int i=0;i<n;i++){
       int x = 0;
       for(int j = 0;j<i;j++){
           if(a[j]<a[i]) x = max(dp[j], x);
       }
       
       dp[i] = 1 + x;
       answer = max(dp[i], answer);
   }
   
   return answer;
}
//////////////////////////////////////////////////////////////////////////
///////////////////////     SOLUTION - 1 | DP O(n^2)
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
///////////////////////     SOLUTION - 2 | O(nlogn)
//////////////////////////////////////////////////////////////////////////
int longestSubsequence(int n, int a[]){
   
   vector<int> v; v.push_back(a[0]);
   
   for(int i=1;i<n;i++){
       if(v[v.size()-1]<a[i]) v.push_back(a[i]);
       else if(v[v.size()-1]==a[i]) continue;
       else{
           auto it = lower_bound(v.begin(), v.end(), a[i]);
           int index = it-v.begin();
           v[index] = a[i];
       }
   }
   
   return v.size();
}
//////////////////////////////////////////////////////////////////////////
///////////////////////     SOLUTION - 2 | O(nlogn)
//////////////////////////////////////////////////////////////////////////


int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}