// Question: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a1c40b0d4c3ad1e5121c212e99e948fd&pid=701331&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
	    string s; cin>>s;
	    int n = s.size();
	    if(n&1){
	        cout<<"not balanced\n";
	        continue;
	    }
	    if(n==0){
	        cout<<"balanced\n";
	        continue;
	    }
	    
	    int arr[n/2+1], top=-1;
	    bool not_balanced = false;
	    for(int i=0;i<n;i++){
	        if(s[i]=='{')       top++, arr[top] = 0;
	        else if(s[i]=='(')  top++, arr[top] = 1;
	        else if(s[i]=='[')  top++, arr[top] = 2;
	        else{
	            if(s[i]=='}'        && arr[top]==0) top--;
    	        else if(s[i]==')'   && arr[top]==1) top--;
    	        else if(s[i]==']'   && arr[top]==2) top--;
    	        else   { not_balanced = true; break;}
	        }
	        if(top>n/2){ not_balanced = true; break;}
	    }
	    
	    if(not_balanced)    cout<<"not balanced\n";
	    else                cout<<"balanced\n";
	}
	
	return 0;
}