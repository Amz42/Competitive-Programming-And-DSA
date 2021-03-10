// Article: https://www.geeksforgeeks.org/count-subsequences-product-less-k/

#include <bits/stdc++.h>
using namespace std;

int SubsequencesProductLessThanK(vector<int> &v, int K){
    int n = v.size();
    int dp[K+1][n+1];
    
    // setting DP to 0
    for(int i=0;i<=K;i++) for(int j=0;j<=n;j++) dp[i][j] = 0;

    for(int i=1;i<=K;i++){
        for(int j=1;j<=n;j++){
            // taking all previous subsequences
            dp[i][j] = dp[i][j-1];

            // if current no. doesn't overflow multiplication over i AND
            // number is not negative
            if( v[j-1] <= i && v[j-1]>0 ){
                dp[i][j] += dp[ (i/v[j-1]) ][j-1] + 1;
            }
        }
    }

    return dp[K][n];
}

int main(){
    vector<int> v = {10};
    cout<<"Number of subsequences with product less than K: ";
    cout<<SubsequencesProductLessThanK(v, 10);
}