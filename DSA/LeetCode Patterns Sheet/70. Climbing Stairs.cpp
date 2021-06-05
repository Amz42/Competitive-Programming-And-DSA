// Question: https://leetcode.com/problems/climbing-stairs/
// Solution: https://leetcode.com/submissions/detail/414547203/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<n+1;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};

int main(){
  return 0;
}