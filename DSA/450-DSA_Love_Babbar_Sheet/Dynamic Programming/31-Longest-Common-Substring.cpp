// Question: https://practice.geeksforgeeks.org/problems/longest-common-substring/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f304749e63b531f651047a5dcf854542&pid=703201&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test; cin>>test;
	while(test--){
	    //
	    
	    int n,m, ans=0; cin>>n>>m;
	    string a,b; cin>>a>>b;
	    
	    int dp[n+1][m+1] = {0};
	    memset(dp, 0, sizeof(dp));
	    
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<m+1;j++){
	            if(a[i-1]==b[j-1]){
	                dp[i][j] = dp[i-1][j-1] + 1;
	            }
	            ans = max(ans, dp[i][j]);
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	
	return 0;
}