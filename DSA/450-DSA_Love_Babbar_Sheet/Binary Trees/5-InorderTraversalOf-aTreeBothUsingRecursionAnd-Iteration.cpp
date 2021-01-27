// Article: https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node* left;
    struct Node* right;
    int data;
};

void inorderIterative(Node *root){
    stack<Node*> stack;
    Node *curr = root;
    
    while (!stack.empty() || curr != nullptr){
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr){
            stack.push(curr);
            curr = curr->left;
        }else{
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top(); stack.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}