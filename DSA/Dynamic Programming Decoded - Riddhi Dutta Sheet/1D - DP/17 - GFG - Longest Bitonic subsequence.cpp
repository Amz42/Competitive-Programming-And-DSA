// Question: https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=4bfadca1cb2f27a64c3f3a8ef4bc0cce&pid=704595&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    vector<int> fun(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 0);
        
        for(int i=0;i<n;i++){
            int max_length_chain = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    max_length_chain = max(
                        max_length_chain,
                        dp[j]
                    );
            }
            
            dp[i] = max_length_chain + 1;
        }
        
        return dp;
    }
    
	public:
	int LongestBitonicSequence(vector<int>nums){
	    auto LIS_Forward = fun(nums);
	    reverse(nums.begin(), nums.end());
	    auto LIS_Backward = fun(nums);
	    
	    int answer = 0, n = nums.size();
	    for(int i=0;i<n;i++)
	        answer = max(answer, LIS_Forward[i] + LIS_Backward[n-i-1] - 1);
	    
	    return answer;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends