### GeeksForGeeks - Symmetric Tree

[Question](https://practice.geeksforgeeks.org/problems/symmetric-tree/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=c4269db370432620e02ff2ced732c267&pid=700583&user=amanguptarkg6)

##### C++
```c++
class Solution{
    bool fun(Node* left, Node* right){
        if(left == NULL && right == NULL) return true;
        if((left == NULL ^ right == NULL) || left->data != right->data)
            return false;
        return fun(left->left, right->right) && fun(left->right, right->left);
    }
public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root){
	    if(root == NULL) return true;
	    return fun(root->left, root->right);
    }
};
```