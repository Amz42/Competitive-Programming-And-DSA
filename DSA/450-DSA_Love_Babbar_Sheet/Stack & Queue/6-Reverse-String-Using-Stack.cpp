// Question: https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a1ee368788c6b09f60ae9f3bab0a5465&pid=700570&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main(){
    long long int t; cin>>t;
    while(t--){
        char str[10000]; cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len); cout<<ch; cout<<endl;
    }
    return 0;
}

//return the address of the string
char* reverse(char *S, int len){
    stack<char> st;
    for(int i=0;i<len;i++) st.push(S[i]);
    
    for(int i=0;i<len;i++){ 
        S[i] = st.top();
        st.pop();
    }
    
    return S;
}