// Question: https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0
// Solution1: https://practice.geeksforgeeks.org/viewSol.php?subId=210d3a5b0394409de48577087b110b84&pid=705274&user=amanguptarkg6
// Solution2: https://practice.geeksforgeeks.org/viewSol.php?subId=fb064f82f1ab9d026696a6b27f239b54&pid=705274&user=amanguptarkg6

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

class Solution2{
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int inc = 1;
		    int dec = 1;
		    
		    for(int i=1;i<nums.size();i++){
		        if(nums[i-1]<nums[i]) inc = dec+1;
		        if(nums[i-1]>nums[i]) dec = inc+1;
		    }
		    
		    return max(inc, dec);
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