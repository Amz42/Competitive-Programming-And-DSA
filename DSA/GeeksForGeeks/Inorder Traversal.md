### GeeksForGeeks - Inorder Traversal

[Question](https://practice.geeksforgeeks.org/problems/inorder-traversal/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=e0c631f1bc25dbc44822bd2b17fd1c30&pid=700135&user=amanguptarkg6)

##### C++
```c++
class Solution {
    void inOrderTraversal(Node* node, vector<int>& ans){
        if(node != NULL) {
            if(node->left != NULL) inOrderTraversal(node->left, ans);
            ans.push_back(node->data);
            if(node->right != NULL) inOrderTraversal(node->right, ans);
        }
    }
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        inOrderTraversal(root, ans);
        return ans;
    }
};
```