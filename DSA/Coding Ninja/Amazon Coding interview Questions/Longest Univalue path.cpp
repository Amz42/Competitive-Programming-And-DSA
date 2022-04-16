// Coding Ninja's Question: https://www.codingninjas.com/codestudio/problems/longest-univalue-path_985291
// LeetCode Question (687): https://leetcode.com/problems/longest-univalue-path/
// Solution1: https://leetcode.com/submissions/detail/495710613/
// Solution2: https://leetcode.com/submissions/detail/495716884/

#include<bits/stdc++.h>
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

// Solution 1
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution1 {
    int fun2(TreeNode* root, int& val){
        if(root == NULL || root->val != val)
            return 0;
        // forming the chain
        return ( 1 + max(fun2(root->left, val),fun2(root->right, val)) );
    }
    int fun(TreeNode* root){
        if(root == NULL) return 0;
        
        int a1 = fun2(root->left, root->val) + fun2(root->right, root->val);
        int a2 = fun(root->left);
        int a3 = fun(root->right);
        
        return max({a1, a2, a3});
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        return fun(root);
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////



// Solution 2
////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution2 {
    int fun(TreeNode* node, int& answer){
        if(node == NULL) return 0;
        
        int left = 0;
        int right = 0;
        
        if(node->left){
            left = fun(node->left, answer);
            if(node->left->val == node->val) left++;
            else left = 0;
        }
        
        if(node->right){
            right = fun(node->right, answer);
            if(node->right->val == node->val) right++;
            else right = 0;
        }
        
        answer = max(answer, left + right);
        return max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int answer = 0;
        fun(root, answer);
        return answer;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
  return 0;
}