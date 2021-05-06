// Question: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=fc0e6b60507443b8b069b2a42c8e271f&pid=705261&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;
// (LRS) LONGEST REPETING SUBSEQUENCE
int main(){
	int tests, n; cin>>tests;
	string s;
	while(tests-->0){
	    cin>>n>>s;
	    
	    int dp[n+1][n+1];
	    for(int i=0;i<n+1;i++) dp[i][0] = dp[0][i] = 0;
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=n;j++){
	            if(s[i-1] == s[j-1] && i!=j) dp[i][j] = dp[i-1][j-1] + 1;
	            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    
	    cout<<dp[n][n]<<endl;
	}
	
	return 0;
}