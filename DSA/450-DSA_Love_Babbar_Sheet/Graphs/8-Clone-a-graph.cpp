// Question: https://leetcode.com/problems/clone-graph/
// Solution: https://leetcode.com/submissions/detail/468944167/

#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    unordered_map <Node*,Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(visited[node]) return visited[node];
        
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        
        for(auto k: node->neighbors)
            cloneNode->neighbors.push_back(cloneGraph(k));
        
        return cloneNode;
    }
};