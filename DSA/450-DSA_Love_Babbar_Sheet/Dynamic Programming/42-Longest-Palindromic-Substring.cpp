// Question: https://leetcode.com/problems/longest-palindromic-substring/
// Solution: https://leetcode.com/submissions/detail/466863005/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
        int n = s.size();
        bool dp[n+1][n+1];
        int EndingHere = 1, MaxLength = 1;
        
        for(int i=0;i<=n;i++) dp[0][i] = dp[1][i] = true;
        
        for(int i=2;i<=n;i++){ // i = Length
            for(int j=i;j<=n;j++){ // j = Ending position of string
                
                // if First == Last Char  AND string in btw is also palindromic
                if(s[j-1]==s[j-i] && dp[i-2][j-1])
                    dp[i][j] = true, MaxLength = i, EndingHere = j;
                else 
                    dp[i][j] = false;
            }
        }
        
        // Calculating answer string
        string answer = "";
        for(int i = EndingHere - MaxLength + 1; i<=EndingHere ; i++ )
            answer += s[i-1];
        
        return answer;
    }
};