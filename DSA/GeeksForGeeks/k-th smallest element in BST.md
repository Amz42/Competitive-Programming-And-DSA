### GeeksForGeeks - k-th smallest element in BST

[Question](https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1/)
| [Solution-1](https://practice.geeksforgeeks.org/viewSol.php?subId=787c51b5c992c59ef4f8d0dac4a3a21f&pid=700498&user=amanguptarkg6)
| [Solution-2](https://practice.geeksforgeeks.org/viewSol.php?subId=8f1d292f6137488cf6e2cb963c44f3dd&pid=700498&user=amanguptarkg6)

#### C++

##### Solution-1
```c++
// Time Complexity: O(n)
// Space Complexity: O(height of tree)

class Solution{
    int answer, i, k;
    void traverse(Node* root){
        if(!root || i>=k) return;
        traverse(root->left);
        i++;
        if(i==k) answer = root->data;
        traverse(root->right);
    }
  public:
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int K){
        i = 0; k = K; answer = -1;
        traverse(root);
        return answer;
    }
};
```

##### Solution-2 (Using Morris Traversal | Tree Modification)
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int i = 0;
        Node* node = root;
        
        while(node){
            if(node->left == NULL) {
                if(++i == K) return node->data;
                node = node->right;
            } else {
                Node* pred = node->left;
                while(pred->right && pred->right != node)
                    pred = pred->right;
                
                if(pred->right == node) {
                    if(++i == K) return node->data;
                    pred->right = NULL;
                    node = node->right;
                } else {
                    pred->right = node;
                    node = node->left;
                }
            }
        }
        
        return -1;
    }
};
```