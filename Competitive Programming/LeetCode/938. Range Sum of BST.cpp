// Question: https://leetcode.com/problems/range-sum-of-bst/
// Solution: https://leetcode.com/submissions/detail/495005739/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int& low, int& high) {
        if(root == NULL) return 0;
        
        if(root->val < low)
            return rangeSumBST(root->right, low, high);
        if(root->val > high)
            return rangeSumBST(root->left, low, high);
        
        return (
            root->val +
            rangeSumBST(root->left, low, high) +
            rangeSumBST(root->right, low, high)
        );
    }
};

int main(){
    return 0;
}