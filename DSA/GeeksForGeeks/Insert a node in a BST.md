### GeeksForGeeks - Insert a node in a BST

[Question](https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=f8c47208cd1f13331ae198b915b8e7ce&pid=700216&user=amanguptarkg6)

#### C++
```c++
// TIme Complexity: O(logn) OR O(max height of tree)
// Space Complexity: O(max height of tree)
Node* insert(Node* root, int Key){
    if(root == NULL)            return (new Node(Key));
    else if(root->data < Key)   root->right = insert(root->right, Key);
    else if(root->data > Key)   root->left = insert(root->left, Key);
    return root;
}
```