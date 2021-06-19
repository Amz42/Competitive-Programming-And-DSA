// Question: https://leetcode.com/problems/longest-repeating-character-replacement/
// Solution: https://leetcode.com/submissions/detail/501321980/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]{0};
        
        int l = 0, r = 0, mx = 0;
        int answer = 0;
        
        while(r < s.size()){
            freq[s[r]-'A']++;
            
            mx = max(mx, freq[s[r]-'A']);
            
            while(mx+k < r-l+1){
                freq[s[l]-'A']--;
                
                mx = 0;
                for(int i=0;i<26;i++) mx = max(mx, freq[i]);
                
                l++;
            }
            
            if(mx+k >= r - l + 1)
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