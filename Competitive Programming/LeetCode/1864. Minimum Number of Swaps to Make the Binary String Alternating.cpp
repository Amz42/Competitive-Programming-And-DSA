// Question: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
// Solution: https://leetcode.com/submissions/detail/494081461/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int fun(string s, bool f){
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            char ch = f ? '1' : '0';
            if(ch!=s[i]) cnt++;
            f = !f;
        }
        
        return (cnt&1 ? INT_MAX : (cnt>>1));
    }
public:
    int minSwaps(string s) {
        int cnt = 0;
        for(auto k: s) (k=='1' ? cnt++ : cnt--);
        if(abs(cnt)>1) return -1;
        
        return min(fun(s,1), fun(s, 0));
    }
};

int main(){
    return 0;
}