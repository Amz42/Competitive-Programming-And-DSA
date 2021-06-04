// Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Solution: https://leetcode.com/submissions/detail/501326076/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        bool present[256]{0};
        
        int answer = 0;
        
        while(r < s.size()){
            int c = s[r];
            
            while(present[c])
                present[s[l++]] = false;
            
            present[c] = true;
            
            answer = max({
                answer,
                r - l + 1
            });
            
            r++;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}