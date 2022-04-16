## InterviewBit: Merge elements

### [Question](https://www.interviewbit.com/problems/merge-elements/)

### C++ Solution
```c++
int mergeElements(
    int l,
    int r,
    vector<int>& A,
    vector<int>& prefixSum,
    vector<vector<int>>& dp
) {
    if(l == r)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];

    int minCost = INT_MAX;
    for(int i=l;i<r;i++) {
        int left = mergeElements(l, i, A, prefixSum, dp);
        int right = mergeElements(i+1, r, A, prefixSum, dp);

        minCost = min(
            minCost,
            left + right + prefixSum[r] - (l > 0 ? prefixSum[l-1] : 0)
        );
    }
    
    return dp[l][r] = minCost;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    vector<int> prefixSum(A.begin(), A.end());
    for(int i=1;i<n;i++)
        prefixSum[i] += prefixSum[i-1];

    return mergeElements(0, n-1, A, prefixSum, dp);
}
```