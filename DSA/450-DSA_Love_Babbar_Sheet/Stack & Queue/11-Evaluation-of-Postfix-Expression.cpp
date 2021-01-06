// Question: https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b5a90feff218dc29d23a03ec4a5189d3&pid=701339&user=amanguptarkg6

// C++ program to evaluate value of a postfix expression
#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string S){
    stack<int> st;
    
    for(int i=0;i<(int)S.size();i++){
        if('0'<=S[i] && S[i]<='9') st.push(S[i]-'0');
        else{
            int y = st.top(); st.pop();
            int x = st.top(); st.pop();
            if(S[i]=='*') st.push(x*y);
            if(S[i]=='/') st.push(x/y);
            if(S[i]=='+') st.push(x+y);
            if(S[i]=='-') st.push(x-y);
        }
    }
    
    return st.top();
}

int main(){
    int t; cin>>t; cin.ignore(INT_MAX, '\n');
    while(t--){
        string S; cin>>S;
        cout<<evaluatePostfix(S)<<endl;
    }
    return 0;
}