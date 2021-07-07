// Question: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// Solution: https://leetcode.com/submissions/detail/518789352/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> answer;
        vector<bool> in_deg(n, 0);
        
        for(auto k: edges)
            in_deg[k[1]] = true;
        
        for(int i=0;i<n;i++)
            if(in_deg[i] == 0)
                answer.push_back(i);
        
        return answer;
    }
};

int main(){
  return 0;
}