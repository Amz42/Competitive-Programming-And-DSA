// Question: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=93464a92bc8188442018010329fd99a5&pid=701901&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x,y,z;
        cin>>x>>y>>z;
        cout<<maximizeTheCuts(n,x,y,z)<<endl;
    }

	return 0;
}

int maximizeTheCuts(int n, int x, int y, int z){
    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    
    for(int i=1;i<=n;i++){
        int a,b,c; a = b = c = -1;
        
        if(i-x >= 0 && dp[i-x]!=-1) a = dp[i-x] + 1;
        if(i-y >= 0 && dp[i-y]!=-1) b = dp[i-y] + 1;
        if(i-z >= 0 && dp[i-z]!=-1) c = dp[i-z] + 1;
        
        dp[i] = max({a,b,c});
    }
    
    return max(dp[n],0);
}