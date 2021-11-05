### GeeksForGeeks - Find the Closest Element in BST

[Question](https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=34ed96bcb34e17085cfde0a27e13e596&pid=700423&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(height of tree)
// Space Complexity: O(height of tree)

class Solution{
public:
    int minDiff(Node *root, int K){
        int answer = INT_MAX;
        Node* node = root;
        
        while(node){
            if(abs(K - node->data) < abs(K - answer))
                answer = node->data;
            node = K < node->data ? node->left : node->right;
        }
        
        return abs(K - answer);
    }
};
```