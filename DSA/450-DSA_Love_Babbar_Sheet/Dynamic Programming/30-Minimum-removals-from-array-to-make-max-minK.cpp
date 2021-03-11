// Article: https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/

#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int MinRemovalFromArrayMakeMaxMinDiffLessEqualToK(int i, int j, int a[], int k){
    if(i>=j) return 0;
    if((a[j]-a[i])<=k) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 1 + min({
        MinRemovalFromArrayMakeMaxMinDiffLessEqualToK(i+1, j, a, k),
        MinRemovalFromArrayMakeMaxMinDiffLessEqualToK(i, j-1, a, k)
    });
    
    return dp[i][j];
}

int main(){

    int k = 4;
    int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
    int n = sizeof(a)/sizeof(a[0]);

    memset(dp, -1, sizeof(dp));
    sort(a, a+n);

    cout << "Minimum Removals to Make Max-Min <= " << k << " : "
         << MinRemovalFromArrayMakeMaxMinDiffLessEqualToK(0,n-1, a, k);

    return 0;
}