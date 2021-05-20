// Question: https://www.codingninjas.com/codestudio/problems/special-binary-tree_920502

#include<bits/stdc++.h>
using namespace std;

/*************************************************************

    Following is the Binary Tree node structure */

    class BinaryTreeNode{
    public :
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

/*************************************************************/

bool isSpecialBinaryTree(BinaryTreeNode* root){
    if(
        (root == NULL) ||
        (root->left == NULL && root->right == NULL)
    ) return true;
    if(root->left == NULL || root->right == NULL)
        return false;
    
    return (
        isSpecialBinaryTree(root->left) && 
        isSpecialBinaryTree(root->right)
    );
}

int main(){
  return 0;
}