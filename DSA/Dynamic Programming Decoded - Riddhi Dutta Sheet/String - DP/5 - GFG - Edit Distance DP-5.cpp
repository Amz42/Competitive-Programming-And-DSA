// Article: https://www.geeksforgeeks.org/edit-distance-dp-5/
// Question: https://practice.geeksforgeeks.org/problems/edit-distance3702/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=39a30cd73ab17154e3846909f4cd16da&pid=703912&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		int editDistance(string s, string t){
		    int n = s.size(), m = t.size();
		    int dp[n+1][m+1];
		    
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=m;j++){
		            if(i==0){ 
		                dp[i][j] = j;
		                continue;
		            }
		            
		            if(j==0){
		                dp[i][j] = i;
		                continue;
		            }
		            
		             if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
		             else{
		                 dp[i][j] = 1 + min({
		                     dp[i][j-1], // Insert Operation
		                     dp[i-1][j-1], // Replace Operation
		                     dp[i-1][j] // Remove operation
		                 });
		             }
		        }
		    }
		    
		    return dp[n][m];
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}