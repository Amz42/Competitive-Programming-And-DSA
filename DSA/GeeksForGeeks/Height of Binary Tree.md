### GeeksForGeeks - Height of Binary Tree

[Question](https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=1ef6d9cdb9741b0acfd597c2b3811710&pid=700164&user=amanguptarkg6)

##### C++
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