// Question: https://leetcode.com/problems/find-the-town-judge/
// Solution: https://leetcode.com/submissions/detail/514436664/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in_deg(n+1, 0);
        vector<bool> can_judge(n+1, 1);
        
        for(auto k: trust){
            can_judge[k[0]] = 0;
            in_deg[k[1]]++;
        }
        
        for(int i=1;i<=n;i++)
            if(can_judge[i] && in_deg[i] == n-1)
                return i;
        
        return -1;
    }
};

int main(){
  return 0;
}