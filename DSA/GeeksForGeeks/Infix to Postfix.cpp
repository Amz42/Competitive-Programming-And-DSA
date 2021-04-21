// Question: https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f782dc3be88386068590cff666d1a4d7&pid=701345&user=amanguptarkg6

// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The main function to convert infix expression
//to postfix expression

class Solution{
    int precedence(char c){
        if(c=='^') return 3;
        if(c=='*' || c=='/') return 2;
        if(c=='+' || c=='-') return 1;
    }
    public:
    string infixToPostfix(string s){
        string a = "";
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if('a'<=s[i] && s[i]<='z') a += s[i];
            else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while(st.top() != '(') a += st.top(), st.pop();
                st.pop();
            }else{
                while(
                    !st.empty() &&
                    st.top() != '(' &&
                    precedence(st.top()) >= precedence(s[i])
                ) a += st.top(), st.pop();
                st.push(s[i]);
            }
        }
        
        while(!st.empty()) a += st.top(), st.pop();
        
        return a;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends