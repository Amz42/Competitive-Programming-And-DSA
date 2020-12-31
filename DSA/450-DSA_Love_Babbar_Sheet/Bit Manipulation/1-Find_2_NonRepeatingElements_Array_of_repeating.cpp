// Question: https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=2832f3474660d9ec93db2feaea0411fe&pid=703807&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution{
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto k: nums) xr ^= k;
        
        // Get the rightmost set bit in set_bit_no
        xr = xr & ~(xr-1);
        
        int set1, set2; set1 = set2 = 0;
        
        for(auto k: nums){
            if(k&xr) set1 ^= k;
            else set2 ^= k;
        }
        
        vector<int> v;
        v.push_back(set1), v.push_back(set2);
        if(v[0]>v[1]) swap(v[0], v[1]);
        
        return v;
    }
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends