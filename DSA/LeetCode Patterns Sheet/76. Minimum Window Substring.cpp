// Question: https://leetcode.com/problems/minimum-window-substring/
// Solution: https://leetcode.com/submissions/detail/501482130/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int fun(char c){
        return ( ('a' <= c && c <= 'z') ? (c - 'a') : (26 + c - 'A') );
    }
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int eligibility_criteria = 0;
        int eligible = 0;
        
        int count[52]{0};
        for(auto k: t) count[fun(k)]++;
        for(auto k: count) if(k>0) eligibility_criteria++;
        
        int l = 0, r = 0;
        int answer = INT_MAX, i, j;
        int freq[52]{0};
        
        while(r<n){
            freq[fun(s[r])]++;
            if(freq[fun(s[r])] == count[fun(s[r])])
                eligible++;
            
            while(eligible == eligibility_criteria){
                if(answer > r-l+1){
                    answer = r-l+1;
                    i = l;
                    j = r;
                }
                
                freq[fun(s[l])]--;
                if(freq[fun(s[l])] == count[fun(s[l])]-1)
                    eligible--;
                l++;
            }
            
            r++;
        }
        
        return ( answer == INT_MAX ? "" : s.substr(i, j - i + 1) );
    }
};

int main(){
  return 0;
}