// Question: https://leetcode.com/problems/minimum-sideway-jumps/
// Solution: https://leetcode.com/contest/weekly-contest-236/submissions/detail/479131261/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obs) {
        int n = obs.size();
        set<int> s; s.insert(2);
        int jumps = 0;
        
        for(int i=0;i<n-1;i++){
            bool passed = 0;
            for(auto k: s){
                if(obs[i+1]!=k){
                    passed = 1;
                    break;
                }
            }
            
            if(!passed){
                jumps++;
                s.insert(1), s.insert(2), s.insert(3);
            }
            
            s.erase(obs[i]), s.erase(obs[i+1]);
        }
        
        return jumps;
    }
};

int main(){
    return 0;
}