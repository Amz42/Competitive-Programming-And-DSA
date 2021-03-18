// LeetCode Question: https://leetcode.com/problems/delete-node-in-a-bst/
// LeetCode Solution: https://leetcode.com/submissions/detail/469399450/
// GFG Question: https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
// GFG Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=0840d3a1b9953b726f0a6e8d0802ae0a&pid=700209&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

/*** Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int inorder_predecessor(TreeNode* root){
        root = root->left;
        while(root->right) root = root->right;
        return root->val;
    }
    int inorder_successor(TreeNode* root){
        root = root->right;
        while(root->left) root = root->left;
        return root->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(key > root->val) root->right = deleteNode(root->right, key);
        else if(key < root->val) root->left = deleteNode(root->left, key);
        else{
            if(root->left == NULL && root->right == NULL) root = nullptr;
            else if(root->left){ // finding predecessor
                root->val = inorder_predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }else{ // finding successor
                root->val = inorder_successor(root);
                root->right = deleteNode(root->right, root->val);
            }
        }
        
        return root;
    }
};

int main(){
    return 0;
}