### GeeksForGeeks - Height of Spiral Tree

[Question](https://practice.geeksforgeeks.org/problems/height-of-spiral-tree/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=e5007c2c7701a72dc5e8c4009c095094&pid=700656&user=amanguptarkg6)

##### C++
```c++
int findTreeHeight(Node* node){
	if(node == NULL) return 0;
	if(node->right && node == node->right->left)
	    return 1;
    
    return max({
        findTreeHeight(node->left),
        findTreeHeight(node->right)
    }) + 1;
}
```