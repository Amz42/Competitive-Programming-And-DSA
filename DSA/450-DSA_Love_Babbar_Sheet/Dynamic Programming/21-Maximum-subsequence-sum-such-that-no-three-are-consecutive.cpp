// Article: https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/

#include <bits/stdc++.h>
using namespace std;

int MaxSubsequenceSumSuchNo3Consecutive(vector<int> &v, int n){
    int dp[n]={0};

    if(n>0) dp[0] = v[0];
    if(n>1) dp[1] = v[0] + v[1];
    if(n>2) dp[2] = max({ v[0]+v[1], v[0]+v[2], v[1]+v[2] });

    for(int i=3;i<n;i++){
        dp[i] = max({
            dp[i-1],                    // leave current element
            dp[i-2] + v[i],             // leave just previous element
            dp[i-3] + v[i] + v[i-1]     // leave previous's previous element
        });
    }

    return dp[n-1];
}

int main(){
    int n = 5;
    vector<int> v = { 3000, 2000, 1000, 3, 10 };
    cout << MaxSubsequenceSumSuchNo3Consecutive(v,n);
    return 0;
}