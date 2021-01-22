// Question: https://practice.geeksforgeeks.org/problems/minimum-swaps/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b67b1ae50de0b32dc5889f83702191d1&pid=700384&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
Make an array of pair having element & index from original array
sort above array
now check if index of element is correct
if not then swap it with index specified in data.second from current element
*/

class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    int n = nums.size();
	    
	    vector<pair<int,int>> v(n);
	    for(int i=0;i<n;i++) v[i] = {nums[i], i};
	    sort(v.begin(), v.end());
	    
	    int answer = 0;
	    for(int i=0;i<n;i++){
	        if(v[i].second != i){
	            answer++;
	            swap(v[i], v[v[i].second]);
	            i--;
	        }
	    }
	    
	    return answer;
	}
};

int main(){
	int tc; cin >> tc; while(tc--){
		int n; cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++) cin >> nums[i];
		Solution obj; int ans = obj.minSwaps(nums); cout << ans <<"\n";
	}
	return 0;
}