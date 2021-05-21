// Question: https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=07415563f871e8260da37080b04d88a9&pid=705274&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&a){
		    int inc = 1;
		    int dec = 1;
		    for(int i=1;i<a.size();i++){
		        if(a[i-1]<a[i]) inc = dec + 1;
		        if(a[i-1]>a[i]) dec = inc + 1;
		    }
		    
		    return max(inc,dec);
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