## [GeeksForGeeks - Height of Binary Tree](https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1/#)

### Solution 1: C++ - Inorder traversal (DFS)
```c++
class Solution{
    int BTreeHeight;
    void fun(Node* node, int i){
        if(node != NULL){
            BTreeHeight = max(BTreeHeight, i + 1);
            fun(node->left, i + 1);
            fun(node->right, i + 1);
        }
    }
public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        BTreeHeight = 0;
        fun(node, 0);
        return BTreeHeight;
    }
};
```

### Solution 2: Java - Inorder traversal (DFS)
```java
class Solution {
    int height(Node node) {
        if(node == null)
            return 0;
        
        int left = height(node.left);
        int right = height(node.right);
        
        return 1 + Math.max(left, right);
    }
}
```