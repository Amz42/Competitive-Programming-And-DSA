### GeeksForGeeks - Full binary tree

[Question](https://practice.geeksforgeeks.org/problems/full-binary-tree/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=99fdfac4e2f3f683dbf66c6d3b107761&pid=700577&user=amanguptarkg6)

##### C++
```c++
bool isFullTree (struct Node* node){
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return true;
    if(node->left != NULL && node->right != NULL)
        return isFullTree(node->left) && isFullTree(node->right);
    return false;
}
```