// Question: https://leetcode.com/problems/backspace-string-compare/
// Solution: https://leetcode.com/submissions/detail/500770001/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    string fun(string s){
        stack<char> st;
        for(auto k: s){
            if(k=='#'){
                if(!st.empty())
                    st.pop();
            }else
                st.push(k);
        }
        
        s = "";
        while(!st.empty()) s += st.top(), st.pop();
        return s;
    }
public:
    bool backspaceCompare(string s, string t) {
        s = fun(s);
        t = fun(t);
        
        return (s==t);
    }
};

int main(){
  return 0;
}