// Question: https://leetcode.com/problems/concatenated-words/
// Solution: https://leetcode.com/submissions/detail/483412856/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> mp;
    bool fun(string s){
        bool dp[1002] = {0}; dp[0] = 1;
        
        for(int i=1;i<=s.size();i++){ // index
            for(int j=1;j<=i;j++){ // length
                if(dp[i-j] && mp[s.substr(i-j, j)]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        mp.clear();
        for(auto k: words) mp[k] = 1;
        
        vector<string> answer;
        for(auto k: words){
            mp[k] = 0;
            if(k!="" && fun(k)) answer.push_back(k);
            mp[k] = 1;
        }
        
        return answer;
    }
};

int main(){
    return 0;
}