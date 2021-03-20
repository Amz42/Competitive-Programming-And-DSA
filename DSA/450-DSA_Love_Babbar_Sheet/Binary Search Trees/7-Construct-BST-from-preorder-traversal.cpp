// Article: https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
// LeetCode Question: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// LeetCode Solution: https://leetcode.com/submissions/detail/469910014/


#include <bits/stdc++.h>
using namespace std;
/* Definition for a binary tree node.*/
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    vector<int> Preorder;
    int size, pos;
    
    void makeBST(TreeNode* root, int L, int R){
        // LEFT SUBTREE
        if(pos >= size || Preorder[pos] < L || R < Preorder[pos]) return;
        if(Preorder[pos] < root->val){
            root->left = new TreeNode(Preorder[pos++]);
            makeBST(root->left, L, root->val);
        }
        
        // RIGHT SUBTREE
        if(pos >= size || Preorder[pos] < L || R < Preorder[pos]) return;
        if(Preorder[pos] > root->val){
            root->right = new TreeNode(Preorder[pos++]);
            makeBST(root->right, root->val, R);
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        size = preorder.size();
        pos = 0;
        Preorder = preorder;
        
        if(size == 0) return NULL;
        TreeNode* root = new TreeNode(Preorder[pos++]);
        if(size == 1) return root;
        
        makeBST(root, INT_MIN, INT_MAX);
        return root;
    }
};

int main(){
    Solution s = *new Solution();
    return 0;
}