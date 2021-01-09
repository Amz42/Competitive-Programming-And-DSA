// Question: https://leetcode.com/problems/maximum-score-from-removing-substrings/
// Solution 1: https://leetcode.com/submissions/detail/440761486/
// Soltuion 2: https://leetcode.com/submissions/detail/440770012/


#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int n = s.size();
        
        if(n==0) return 0;
        
        int answer = 0;
        char g='a',h='b'; // target 'ab' by default first
        if (x<y) swap(g,h), swap(x,y);
        
        for(int i=0;i<n;i++){
            if(s[i]==h && !st.empty() && st.top()==g){
                st.pop();
                answer += x;
            }else st.push(s[i]);
        }
        
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        
        reverse(s.begin(), s.end());
        
        for(int i=0;i<(int)s.size();i++){
            if(s[i]==g && !st.empty() && st.top()==h){
                st.pop();
                answer += y;
            }else st.push(s[i]);
        }
        
        return answer;
    }
};


class Solution2 {
public:
    int remove(string &s, string to_remove, int profit){
        int i=0, total_profit = 0;
        for(int j=0;j<(int)s.size();j++){
            s[i++] = s[j];
            if( i>1 && s[i-2]==to_remove[0] && s[i-1]==to_remove[1] ) total_profit += profit, i-=2;
        }
        
        s.resize(i);
        return total_profit;
    }
    
    int maximumGain(string s, int x, int y) {
        return (
            x>y ?
            remove(s, "ab", x) + remove(s, "ba", y) :
            remove(s, "ba", y) + remove(s, "ab", x)
        );
    }
};