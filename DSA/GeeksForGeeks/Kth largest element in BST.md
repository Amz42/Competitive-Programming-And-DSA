### GeeksForGeeks - Kth largest element in BST

[Question](https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=e3826bbb73544ad9d00e18cd7ad271a5&pid=700427&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(Height of tree + K)
// Space Complexity: O(Height of tree)

class Solution {
    int fun(Node* node, int& i, int& K){
        if(node == NULL) return -1;
        
        int ans = fun(node->right, i, K);
        
        if(ans != -1)
            return ans;
        if(++i == K)
            return node->data;
        
        return fun(node->left, i, K);
    }
public:
    int kthLargest(Node *root, int K){
        int i = 0;
        return fun(root, i, K);
    }
};
```