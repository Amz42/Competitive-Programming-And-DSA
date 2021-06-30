// Question: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Solution1: https://leetcode.com/submissions/detail/514455932/
// Solution2: https://leetcode.com/submissions/detail/514460465/

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto k: s){
            if(st.size() && st.top() == k)
                st.pop();
            else
                st.push(k);
        }
        
        s = "";
        while(!st.empty()) s += st.top(), st.pop();
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};

class Solution2 {
public:
    string removeDuplicates(string s) {
        int i = 0;
        for(int j=0; j<s.size(); j++, i++){
            s[i] = s[j];
            if(i>0 && s[i-1] == s[i])
                i -= 2;
        }
        
        return s.substr(0, i);
    }
};

int main(){
  return 0;
}