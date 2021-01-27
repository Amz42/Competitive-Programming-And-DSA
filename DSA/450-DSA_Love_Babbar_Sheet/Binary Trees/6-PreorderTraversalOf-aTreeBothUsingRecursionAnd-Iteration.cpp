// Article: https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node* left;
    struct Node* right;
    int data;
};

// Iterative function to perform preorder traversal on the tree
void preorderIterative(Node *root){
    if (root == nullptr) return;
 
    // create an empty stack and push the root node
    stack<Node*> stack; stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty()){
        Node *curr = stack.top(); stack.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) stack.push(curr->right);
 
        // push the left child of the popped node into the stack
        if (curr->left) stack.push(curr->left);
 
        // the right child must be pushed first so that the left child
        // is processed first (FIFO order)
    }
}