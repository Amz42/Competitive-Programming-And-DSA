// Question: https://leetcode.com/problems/minimum-height-trees/
// Solution: https://leetcode.com/submissions/detail/514423956/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        
        for(auto k: edges){
            int x = k[0], y = k[1];
            graph[x].insert(y), graph[y].insert(x);
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
            if(graph[i].size() <= 1)
                q.push(i);
        
        int remaining_nodes = n;
        while(remaining_nodes > 2){
            int qsize = q.size();
            remaining_nodes -= qsize;
            
            for(int i=0;i<qsize;i++){
                int node = q.front(); q.pop();
            
                for(auto k: graph[node]){
                    graph[k].erase(node);
                    if(graph[k].size() == 1)
                        q.push(k);
                }

                graph[node].clear();
            }
        }
        
        vector<int> answer;
        while(!q.empty()) answer.push_back(q.front()), q.pop();
        return answer;
    }
};

int main(){
  return 0;
}