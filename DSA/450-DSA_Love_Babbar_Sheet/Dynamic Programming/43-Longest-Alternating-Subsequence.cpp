// Question: https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=210d3a5b0394409de48577087b110b84&pid=705274&user=amanguptarkg6



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
	public:
	    int CalcSign(int i){
	        if(i<0) return -1;
	        else if(i>0) return +1;
	        return 0;
	    }
	
		int AlternatingaMaxLength(vector<int>&nums){
		    int n = nums.size();
		    int LastSign = 0, answer = 1;
		    
		    
		    for(int i=1;i<n;i++){
		        int Sign  = CalcSign(nums[i]-nums[i-1]);
		        if(Sign != LastSign && Sign!=0 ){
		            LastSign = Sign;
		            answer++;
		        }
		    }
		    
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
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends