// Question: https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
// Solution1: https://practice.geeksforgeeks.org/viewSol.php?subId=7ae14e48d2bd1a3636c51e690c3da102&pid=704157&user=amanguptarkg6
// Solution2: https://practice.geeksforgeeks.org/viewSol.php?subId=5f4a0809e5cba258775379d990b92211&pid=704157&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

/////////////////////////////////////////////////////////////////////// Solution 1
typedef long long ll;
class Solution{
	public:
    	long long getCount(int N){
    		ll dp[10]; for(int i=0;i<10;i++) dp[i] = 1;
    		
    		for(int i=1;i<N;i++){
    		    ll temp[10];
    		    temp[0] = dp[0] + dp[8];
    		    temp[1] = dp[1] + dp[2] + dp[4];
    		    temp[2] = dp[2] + dp[1] + dp[5] + dp[3];
    		    temp[3] = dp[3] + dp[2] + dp[6];
    		    temp[4] = dp[4] + dp[1] + dp[5] + dp[7];
    		    temp[5] = dp[5] + dp[2] + dp[4] + dp[6] + dp[8];
    		    temp[6] = dp[6] + dp[3] + dp[5] + dp[9];
    		    temp[7] = dp[7] + dp[4] + dp[8];
    		    temp[8] = dp[8] + dp[7] + dp[9] + dp[5] + dp[0];
    		    temp[9] = dp[9] + dp[8] + dp[6];
    		    
    		    for(int j=0;j<10;j++) dp[j] = temp[j];
    		}
    		
    		ll answer = 0;
    		for(int j=0;j<10;j++) answer += dp[j];
    		
    		return answer;
    	}
};
/////////////////////////////////////////////////////////////////////// Solution 1





/////////////////////////////////////////////////////////////////////// Solution 2
typedef long long ll;
class Solution2{
	public:
	ll dp[10][26];
	int KeyPad[4][3] = {
	    {1,2,3},
	    {4,5,6},
	    {7,8,9},
	    {-1,0,-1}
	};
	
	ll solve(int i, int j, int n){
	    if(KeyPad[i][j] == -1) return 0;
	    if(n==1) return 1;
	    if(dp[ KeyPad[i][j] ][n] != -1) return dp[ KeyPad[i][j] ][n];
	    
	    ll a = solve(i,j,n-1);
	    ll b = i-1>=0 ? solve(i-1, j, n-1) : 0;
	    ll c = j-1>=0 ? solve(i, j-1, n-1) : 0;
	    ll d = i+1<=3 ? solve(i+1, j, n-1) : 0;
	    ll e = j+1<=2 ? solve(i, j+1, n-1) : 0;
	    
	    return dp[ KeyPad[i][j] ][n] = a+b+c+d+e;
	}
	
	long long getCount(int N){
		memset(dp, -1, sizeof(dp));
		
		ll answer = 0;
		for(int i=0;i<4;i++){
		    for(int j=0;j<3;j++){
		        if(KeyPad[i][j] != -1)
		            answer += solve(i, j, N);
		    }
		}
		
		return answer;
	}
};
/////////////////////////////////////////////////////////////////////// Solution 2


int main(){
   	int t; cin >> t; while (t--){
        int n; cin >> n;
        Solution ob; cout << ob.getCount(n) << "\n"; 
    }
    return 0;
}