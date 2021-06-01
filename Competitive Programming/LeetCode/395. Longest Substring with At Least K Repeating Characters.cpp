// Question: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
// Solution: https://leetcode.com/submissions/detail/500890138/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int SlidingWindow(string s, int k, int &freq){
        int count[26]{0};
        int n = s.size();
        int l = 0, r = 0, types = 0, eligible = 0;
        int MaxWindowLength = 0;
        
        while(r<n){
            count[s[r]-'a']++;
            if(count[s[r]-'a']==1)
                types++;
            
            if(count[s[r]-'a'] == freq)
                eligible++;
            
            while(l<=r && types>k){
                count[s[l]-'a']--;
                if(count[s[l]-'a'] == 0)
                    types--;
                if(count[s[l]-'a'] == freq-1)
                    eligible--;
                l++;
            }
            
            if(types==k && eligible==types)
                MaxWindowLength = max({
                    MaxWindowLength,
                    r-l+1
                });
            r++;
        }
        
        return MaxWindowLength;
    }
public:
    int longestSubstring(string s, int freq) {
        int answer = 0;
        
        set<char> st(s.begin(), s.end());
        int MaxUnique = st.size();
        
        for(int CurrentUnique = 1; CurrentUnique <= MaxUnique; CurrentUnique++){
            answer = max({
                answer,
                SlidingWindow(s, CurrentUnique, freq)
            });
        }
        
        return answer;
    }
};

int main(){
  return 0;
}