### GeeksForGeeks - Remove Half Nodes

[Question](https://practice.geeksforgeeks.org/problems/remove-half-nodes/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=8d2c48a3df1a9058993984896330921d&pid=700652&user=amanguptarkg6)

##### C++
```c++
Node *RemoveHalfNodes(Node *node){
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return node;
        
    node->left = RemoveHalfNodes(node->left);
    node->right = RemoveHalfNodes(node->right);
    
    if(node->left == NULL) return node->right;
    if(node->right == NULL) return node->left;
    return node;
}
```