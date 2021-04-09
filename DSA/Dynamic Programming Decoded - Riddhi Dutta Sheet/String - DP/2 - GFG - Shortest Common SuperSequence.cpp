// GFG Article: https://www.geeksforgeeks.org/shortest-common-supersequence/
// (LeetCode) Question: https://leetcode.com/problems/shortest-common-supersequence/
// (LeetCode) Solution: https://leetcode.com/submissions/detail/478471024/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int dp[1001][1001];
        
        for(int i=0;i<=str1.size();i++){
            for(int j=0;j<=str2.size();j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    continue;
                }
                
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
            }
        }
        
        int lcs = dp[str1.size()][str2.size()];
        vector<int> s1, s2;
        int x = str1.size(), y = str2.size();
        while(x>0 && y>0){
            if(str1[x-1] == str2[y-1])
                s1.push_back(--x), s2.push_back(--y);
            else
                if(dp[x-1][y] == dp[x][y]) x--;
                else if(dp[x][y-1] == dp[x][y]) y--;
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        string answer = "";
        x = y = 0;
        for(int i=0;i<lcs;i++){
            while(x<s1[i]) answer += str1[x++];
            while(y<s2[i]) answer += str2[y++];
            answer += str1[x];
            x++, y++;
        }
        while(str1[x]) answer += str1[x++];
        while(str2[y]) answer += str2[y++];
        
        return answer;
    }
};

int main(){
    return 0;
}