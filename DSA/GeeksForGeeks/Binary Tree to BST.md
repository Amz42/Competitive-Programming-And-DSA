### GeeksForGeeks - Binary Tree to BST

[Question](https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=71ec3d2ab519794f3542b4267a637505&pid=700263&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution{
    void fun(Node* node, vector<int>& v){
        if(node == NULL) return;
        
        fun(node->left, v);
        v.push_back(node->data);
        fun(node->right, v);
    }
    void fun2(Node* node, vector<int>& v, int& i){
        if(node == NULL) return;
        
        fun2(node->left, v, i);
        node->data = v[i++];
        fun2(node->right, v, i);
    }
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root){
        vector<int> v;
        int i = 0;
        
        fun(root, v);
        sort(v.begin(), v.end());
        fun2(root, v, i);
        
        return root;
    }
};
```