## [Check for Balanced Tree](https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1)

#### Solution 1: C++ - DFS & Height of Binary tree
```c++
bool balanced;

int fun(Node* node){
    if(node == NULL) return 0;
    int left = fun(node->left);
    int right = fun(node->right);
    if(abs(left-right)>1) balanced = false;
    return (1 + max(left, right));
}

bool isBalanced(Node *root){
    balanced = true;
    fun(root);
    return balanced;
}
```

#### Solution 2: Java - DFS & Height of Binary tree
```java
class Tree {
    boolean balanced;
    int height(Node root) {
        if(root == null) return 0;
        
        int left = height(root.left);
        int right = height(root.right);
        
        if(Math.abs(left - right) > 1)
            balanced = false;
        
        return Math.max(left, right) + 1;
    }
    
    boolean isBalanced(Node root) {
        balanced = true;
        height(root);
        return balanced;
    }
}
```
