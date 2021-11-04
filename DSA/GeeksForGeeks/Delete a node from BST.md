### GeeksForGeeks - Delete a node from BST

[Question](https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=d245ebf9c2636bf85f89998a02a02d96&pid=700209&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(height of tree)
// Space Complexity: O(height of tree)

int predecessor(Node* node){
    node = node->left;
    while(node->right) node = node->right;
    return node->data;
}

int successor(Node* node){
    node = node->right;
    while(node->left) node = node->left;
    return node->data;
}

// Function to delete a node from BST.
Node* deleteNode(Node* root, int X) {
    if(root == NULL) return root;
    else if(X < root->data) root->left = deleteNode(root->left, X);
    else if(X > root->data) root->right = deleteNode(root->right, X);
    else {
        if(root->left == NULL && root->right == NULL)
            root = NULL;
        else if(root->left){
            root->data = predecessor(root);
            root->left = deleteNode(root->left, root->data);
        }else{
            root->data = successor(root);
            root->right = deleteNode(root->right, root->data);
        }
    }
    
    return root;
}
```