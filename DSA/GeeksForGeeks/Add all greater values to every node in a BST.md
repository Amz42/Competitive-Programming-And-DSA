### GeeksForGeeks - Add all greater values to every node in a BST

[Question](https://practice.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=e2d6a2ab52e45bc3c39439a9a3b90baa&pid=700177&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(height of tree)

void fun(Node* node, int& sum){
    if(node == NULL)
        return;
    
    fun(node->right, sum);
    sum = node->data = node->data + sum;
    fun(node->left, sum);
}

Node* modify(Node *root){
    int sum = 0;
    fun(root, sum);
    return root;
}
```