// Question: https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=9ba2d9cb184ff799d8b3d023be99b7ce&pid=703404&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    // APPROACH:
    // Kadane's Algorithm
	int maxSubstring(string S){
	    int sum = 0;
	    int mx_sum = INT_MIN;
	    
	    for(auto k: S){
	        sum += (k == '0' ? 1 : -1);
	        mx_sum = max(mx_sum, sum);
	        sum = max(sum, 0);
	    }
	    
	    return mx_sum;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends