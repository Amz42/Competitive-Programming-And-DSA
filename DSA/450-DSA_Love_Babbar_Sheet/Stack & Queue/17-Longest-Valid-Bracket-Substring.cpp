// Question: https://practice.geeksforgeeks.org/problems/valid-substring0624/1#
// Solution 1: https://practice.geeksforgeeks.org/viewSol.php?subId=a3efac83b417b006c3d37d6428529ea4&pid=703534&user=amanguptarkg6
// Solution 2: https://practice.geeksforgeeks.org/viewSol.php?subId=5fa98ecf1f0c1b23c2fe6d165b2eb99d&pid=703534&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

// SOLUTION - 1
class Solution {
  public:
    int findMaxLen(string s) {
        stack<int> st; st.push(-1);
        int answer = 0;
        
        for(int i=0;i<(int)s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else answer = max(answer, i-st.top());
            }
        }
        
        return answer;
    }
};

/*
APPROACH:
    Make a stack, Initially push -1 in stack,
    for each char in string:
        if its '(' then push its index in stack
        else:
            pop last element from stack
            if stack is empty now then it was an irregularity
                So push its index in stack
            else its a regular '()' string
                So, from top of stack(that is last irregularity)
                get the difference from current index & update the answer
*/

// SOLUTION - 2
class Solution2 {
  public:
    int findMaxLen(string s) {
        int l = 0, r = 0, n = s.size(), answer = 0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') l++;
            else r++;
            if(l==r) answer = max(answer,2*l);
            else if(r>l) l=r=0;
        }
        
        l = r = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') l++;
            else r++;
            if(l==r) answer=max(answer,2*l);
            else if(l>r) l=r=0;
        }
        
        return answer;
    }
};

int main() {
    int t; cin >> t; while (t--) {
        string S; cin >> S; 
        Solution ob; cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}