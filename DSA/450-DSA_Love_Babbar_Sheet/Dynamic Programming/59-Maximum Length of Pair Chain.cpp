// GFG Question: https://practice.geeksforgeeks.org/problems/max-length-chain/1
// GFG Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=3fc46eaf5c2649741f2ec8369154cf3b&pid=700342&user=amanguptarkg6
// LeetCode Question: https://leetcode.com/problems/maximum-length-of-pair-chain/
// LeetCode Solution: https://leetcode.com/submissions/detail/489542568/



//////////////////////////////////////////////////////////////////////
// LeetCode Solution
//////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findLongestChain(vector<vector<int>>& vec) {
        int n=vec.size();
        
        sort(vec.begin(),vec.end());
        int dp[n];
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;i++){

            for(int j=0;j<i;j++){
                if(vec[j][1] < vec[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp,dp+n)+1;
    }
};
//////////////////////////////////////////////////////////////////////
// LeetCode Solution
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// GFG Solution
//////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[], int n){
    //Your code here
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){v.push_back(make_pair(p[i].first, p[i].second));}
    sort(v.begin(),v.end());
    
    int dp[n];
    
    for(int i=0;i<n;i++){
        int x = 0;
        for(int j=0;j<i;j++){
            if(v[j].second<v[i].first)
                x = max(x,dp[j]);
        }
        dp[i] = x+1;
    }
    
    return *max_element(dp,dp+n);
}
//////////////////////////////////////////////////////////////////////
// GFG Solution
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////