// Question: https://leetcode.com/problems/course-schedule-ii/
// Solution: https://leetcode.com/submissions/detail/514043403/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<int> in_deg(n,0);
        vector<int> graph[n];
        
        for(int i=0;i<v.size();i++)
            graph[v[i][1]].push_back(v[i][0]),
            in_deg[v[i][0]]++;
        
        queue<int> q;
        for(int i=0;i<n;i++)
            if(in_deg[i] == 0)
                q.push(i);
        
        vector<int> answer;
        while(!q.empty()){
            int node = q.front(); q.pop();
            answer.push_back(node);
            
            for(auto k: graph[node])
                if(--in_deg[k] == 0)
                    q.push(k);
        }
        
        if(answer.size() != n) answer.clear();
        
        return answer;
    }
};

int main(){
  return 0;
}