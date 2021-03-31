// Question: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Solution: https://leetcode.com/submissions/detail/474506603/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    map<int, vector<pair<int,int>>> mp;
    
    void traverse(TreeNode* node, int row, int col){
        if(node == NULL) return;
        mp[col].push_back({row,node->val});
        traverse(node->left, row+1, col-1);
        traverse(node->right, row+1, col+1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        mp.clear();
        traverse(root, 0, 0);
        
        vector<vector<int>> answer;
        for(auto k: mp){
            sort(k.second.begin(), k.second.end());
            
            vector<int> v;
            for(auto i: k.second) v.push_back(i.second);
            
            answer.push_back(v);
        }
        
        return answer;
    }
};

int main(){
    return 0;
}