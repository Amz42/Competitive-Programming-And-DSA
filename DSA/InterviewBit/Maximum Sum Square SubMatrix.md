## InterviewBit: Maximum Sum Square SubMatrix

### [Question](https://www.interviewbit.com/problems/maximum-sum-square-submatrix/)

### C++ Solution
```c++
int Solution::solve(vector<vector<int>> &A, int B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] =
                + A[i-1][j-1]   // self
                + dp[i-1][j]    // all above rows in matrix
                + dp[i][j-1]    // all before columns in matrix
                - dp[i-1][j-1];
        }
    }

    int answer = INT_MIN;

    for(int i=B;i<=n;i++) {
        for(int j=B;j<=m;j++) {
            answer = max(
                answer,
                dp[i][j] - dp[i-B][j] - dp[i][j-B] + dp[i-B][j-B]
            );
        }
    }

    return answer;
}
```