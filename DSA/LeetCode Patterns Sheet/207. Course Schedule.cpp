// Question: https://leetcode.com/problems/course-schedule/
// Solution: https://leetcode.com/submissions/detail/514037898/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        vector<int> in_deg(n, 0);
        vector<int> graph[n];
        
        for(int i=0;i<v.size();i++)
            graph[v[i][1]].push_back(v[i][0]),
            in_deg[v[i][0]]++;
        
        queue<int> q;
        int cnt = 0;
        
        for(int i=0;i<n;i++)
            if(in_deg[i] == 0)
                q.push(i);
        
        while(!q.empty()){
            cnt++;
            int node = q.front(); q.pop();
            
            for(auto k: graph[node])
                if(--in_deg[k] == 0)
                    q.push(k);
        }
        
        return (cnt == n);
    }
};

int main(){
  return 0;
}