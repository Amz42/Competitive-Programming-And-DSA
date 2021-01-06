// Question: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=fbdaa517d854ba2003451495c247c010&pid=700253&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int celebrity(vector<vector<int>> &M, int n) {
        stack<int> s;
        
        //push i-th person in stack
        for(int i=0;i<n;i++) s.push(i);
        
        while(s.size()>=2){
            int x = s.top(); s.pop();
            int y = s.top(); s.pop();
            
            // if:      x knows y, then x can't be celeb
            // else:    y is not known by x, so y can't be celeb
            s.push(M[x][y] == 1 ? y : x);
        }
        
        int celeb_candidate = s.top(); s.pop();
        
        for(int i=0;i<n;i++){
            if(
                i!=celeb_candidate &&
                (
                    M[celeb_candidate][i] == 1 ||   // celeb knows i-th person
                    M[i][celeb_candidate] == 0      // i-th doesn't know celeb_candidate
                )
            ) return -1;
        }
        
        return celeb_candidate;
    }
};

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<vector<int>> M(n, vector<int> (n, 0));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>M[i][j];
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;
    }
}