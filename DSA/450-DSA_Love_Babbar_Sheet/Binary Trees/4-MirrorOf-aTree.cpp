// Article: https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/

#include <bits/stdc++.h>
using namespace std;

typedef struct treenode { 
    int val; 
    struct treenode* left; 
    struct treenode* right; 
} node; 
  
// Helper function that allocates a new node with the 
// given data and NULL left and right pointers 
node* createNode(int val) 
{ 
    node* newNode = (node*)malloc(sizeof(node)); 
    newNode->val = val; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 
//////////////////////////////////////////////////////////////////////////////////////
void mirrorify(node* root, node** mirror) {
    if (root == NULL){
        mirror = NULL;
        return;
    }
  
    // Create new mirror node from original tree node 
    *mirror = createNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}