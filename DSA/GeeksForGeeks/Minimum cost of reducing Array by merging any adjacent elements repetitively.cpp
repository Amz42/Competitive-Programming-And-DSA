// Article: https://www.geeksforgeeks.org/minimum-cost-of-reducing-array-by-merging-any-adjacent-elements-repetitively/

#include <bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return (a<b ? a : b);
}
int findMinCost(vector<int> &arr, int n){
    int dp[n+5][n+5];
    for(int i=0;i<n+5;i++) dp[i][i] = 0;
    
    const int inf = 1e9;
    int pref[n+5] = {0};
    for(int i=0;i<n;i++) pref[i+1] = pref[i] + arr[i];
    
    for(int len=2;len<=n;len++){
        for(int index=len;index<=n;index++){
            int start = index-len+1;
            dp[start][index] = inf;
            int sum = pref[index] - pref[start-1];
            
            for(int k=start;k<index;k++){
                dp[start][index] = min(
                    dp[start][index],
                    dp[start][k] + dp[k+1][index] + sum
                );
            }
        }
    }
    
    return dp[1][n];
}

int main(){
    return 0;
}