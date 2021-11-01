### GeeksForGeeks - Sum of Left Leaf Nodes

[Question](https://practice.geeksforgeeks.org/problems/sum-of-left-leaf-nodes/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=3043d82161a304bef05fc51a2c5ff053&pid=700667&user=amanguptarkg6)

##### C++
```c++
void fun(Node* node, int& answer){
    if(node == NULL) return;
    
    Node* left = node->left;
    Node* right = node->right;
    
    if(left != NULL && left->left == NULL && left->right == NULL)
        answer += left->data;
    
    fun(left, answer);
    fun(right, answer);
}

int leftLeavesSum(Node *root){
    int answer = 0;
    fun(root, answer);
    return answer;
}
```