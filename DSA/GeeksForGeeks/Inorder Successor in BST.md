### GeeksForGeeks - Inorder Successor in BST

[Question](https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=263934613feefadd526b531cc03bc5a9&pid=700514&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(Height of the BST)
// Space Complexity: O(1)

class Solution{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* inOrderSuccessor(Node *root, Node *x){
        Node* prev = NULL;
        
        while(root){
            if(root->data > x->data && (prev == NULL || root->data < prev->data))
                prev = root;
            if(root->data <= x->data)
                root = root->right;
            else
                root = root->left;
        }
        
        if(prev && prev->data <= x->data)
            return NULL;
        return prev;
    }
};
```