// Question: https://leetcode.com/problems/word-break/
// Solution: https://leetcode.com/submissions/detail/415127110/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if(n==0) return true;
        
        bool dp2[100005] = {0}; dp2[0]=1;
        unordered_map<string, bool> mp;
        
        for(auto k: wordDict) mp[k] = 1;
        
        for(int j = 1;j<n+1;j++){
            for(int i = 1;i<=j;i++){
                string k = s.substr(j-i,i);
                if(mp[k] && dp2[j-i]) dp2[j] = 1;
            }
        }
        
        return dp2[n];
    }
};

int main(){
    Solution s;
    return 0;
}