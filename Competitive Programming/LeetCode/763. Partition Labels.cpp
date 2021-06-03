// Question: https://leetcode.com/problems/partition-labels/
// Solution: https://leetcode.com/submissions/detail/501892371/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26]{0};
        
        for(int i = 0; i < s.size(); i++)
            last[s[i]-'a'] = i;
        
        vector<int> answer;
        
        int startPtr = 0, max_reach = 0;
        
        for(int i = 0; i < s.size(); i++){
            max_reach = max({
                max_reach,
                last[s[i]-'a']
            });
            
            if(i == max_reach){
                answer.push_back(i - startPtr + 1);
                startPtr = i + 1;
            }
        }
        
        return answer;
    }
};

int main(){
  return 0;
}