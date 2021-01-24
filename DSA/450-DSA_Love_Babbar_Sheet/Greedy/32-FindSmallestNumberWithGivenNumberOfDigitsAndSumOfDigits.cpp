// Question: https://practice.geeksforgeeks.org/problems/smallest-number5829/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b01a8e5e11815d3a968a099a057c8ee3&pid=704350&user=amanguptarkg6

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string smallestNumber(int S, int D){
        
        if(S>9*D) return "-1";
        if(S==0) return (D==1 ? "0" : "-1");
        
        string ans = "1" + string(D-1,'0');
        S--;
        
        int i = D-1;
        while(S>0 && i>0){
            int digit = min(9,S);
            S -= digit;
            ans[i] = (char)('0' + digit);
            i--;
        }
        
        if(S>0) ans[0] = (char)('0' + (S+1) );
        
        return ans;
    }
};

int main(){
    int t; cin>>t;
    while(t--){
        int S,D; cin >> S >> D;
        Solution ob; cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}