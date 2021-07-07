// Question: https://leetcode.com/problems/all-paths-from-source-to-target/
// Solution: https://leetcode.com/submissions/detail/518786031/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    void dfs(
        int node,
        vector<int>& path,
        vector<vector<int>>& answer,
        vector<vector<int>>& graph
    ){
        path.push_back(node);
        
        if(node == n-1)
            answer.push_back(path);
        
        for(int k: graph[node])
            dfs(k, path, answer, graph);
        
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>> answer;
        vector<int> path;
        dfs(0, path, answer, graph);
        
        return answer;
    }
};

int main(){
  return 0;
}