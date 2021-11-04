### GeeksForGeeks - Check for BST

[Question](https://practice.geeksforgeeks.org/problems/check-for-bst/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=fe7d8e35358663d4933f40f444d85b4d&pid=700149&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(height of tree)

class Solution{
    bool fun(Node* node, int mn, int mx){
        if(node == NULL)
            return true;
        if(node->data < mn || node->data > mx)
            return false;
        
        return fun(node->left, mn, node->data - 1) && fun(node->right, node->data + 1, mx);
    }
public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        return fun(root, INT_MIN, INT_MAX);
    }
};
```