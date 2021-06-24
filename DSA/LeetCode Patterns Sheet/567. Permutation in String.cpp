// Question: https://leetcode.com/problems/permutation-in-string/
// Solution: https://leetcode.com/submissions/detail/498044878/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string a, string b) {
        int n  = a.size();
        int m = b.size();
        
        if(m<n) return false;
        
        int A[26] = {0}, B[26] = {0};
        for(int i=0;i<n;i++)
            A[a[i]-'a']++;
        
        for(int i=0;i<n-1;i++)
            B[b[i]-'a']++;
        
        
        for(int i=n-1;i<m;i++){
            B[b[i]-'a']++;
            
            bool done = true;
            for(int j=0;j<26;j++)
                if(A[j] != B[j]){
                    done = false;
                    break;
                }
            
            if(done) return true;
            B[b[i-n+1]-'a']--;
        }
        
        return false;
    }
};

int main(){
  return 0;
}