// Question: https://practice.geeksforgeeks.org/problems/array-to-bst4443/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=c06789817c4587fa4f2eb7fabe035b39&pid=705723&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> answer;
    void makeBBST(vector<int>& keys, int i, int j){
        if(i>j) return;
        int mid = (i+j)/2;
        answer.push_back(keys[mid]);
        makeBBST(keys, i, mid-1);
        makeBBST(keys, mid+1, j);
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        answer.clear();
        makeBBST(nums, 0, nums.size()-1);
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends