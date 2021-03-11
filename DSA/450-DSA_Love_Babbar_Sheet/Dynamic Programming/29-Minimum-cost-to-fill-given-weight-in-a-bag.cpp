// Question: https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=66a08d57b37362af09a0df752ccfe125&pid=704039&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int minimumCost(int cost[], int N, int W){
        long long int dp[N+1][W+1];
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=W;j++){
                // if (capacity == 0)    =>   (cost = 0)
                if(j==0){
                    dp[i][j] = 0;
                    continue;
                }
                
                // No packet can be picked
                if(i==0){
                    dp[i][j] = INT_MAX;
                    continue;
                }
                
                // Packet is available AND
                // weight of packet is <= current capacity
                if(cost[i-1]!=-1 && i<=j){
                    dp[i][j] = min({
                        dp[i-1][j],
                        dp[i][j-i] + cost[i-1]
                    });
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (dp[N][W] == INT_MAX ? -1 : dp[N][W]);
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends