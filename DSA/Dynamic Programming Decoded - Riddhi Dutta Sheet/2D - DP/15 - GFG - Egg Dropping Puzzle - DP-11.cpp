// Article: https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][10001];
    int EggDrop(int eggs, int floors) {
        memset(dp, 0, sizeof dp);
        
        for(int i=1;i<=eggs;i++){
            for(int j=0;j<=floors;j++){
                // 0 floors => 0 trials
                // 1 floors => 1 trials
                // 1 egg => no_of_floors trials
                if(j <= 1 || i==1){
                    dp[i][j] = j;
                    continue;
                }
                
                int answer = floors;
                // trial is done on k-th floor
                for(int k=1;k<=j;k++){
                    answer = min(
                        answer,
                        max(
                            dp[i-1][k-1],   // egg breaks
                            dp[i][j-k]      // egg doesn't break
                        )
                    );
                }
                
                // 1 trial is done on current floor
                dp[i][j] = answer + 1;
            }
        }
        
        return dp[eggs][floors];
    }
};

int main(){
    return 0;
}