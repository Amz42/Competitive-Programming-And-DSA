// Question: https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=497bf9e70fc0f2846c109c2462138dbd&pid=703341&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests; cin>>tests;
	while(tests-->0){
	    int n,m,p; cin>>n>>m>>p;
	    string s1,s2,s3; cin>>s1>>s2>>s3;
	    
	    int dp[n+1][m+1][p+1];
	    
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            for(int k=0;k<=p;k++){
	                if(i==0 || j==0 || k==0) dp[i][j][k] = 0;
	                else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
	                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
	                }else{
	                    dp[i][j][k] = max({
	                        dp[i-1][j][k],
	                        dp[i][j-1][k],
	                        dp[i][j][k-1]
	                    });
	                }
	            }
	        }
	    }
	    
	    cout<<dp[n][m][p]<<"\n";
	}
	
	return 0;
}