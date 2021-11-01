### GeeksForGeeks - Mirror Tree

[Question](https://practice.geeksforgeeks.org/problems/mirror-tree/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=32320c9b24e0069272ce1469f3d920e7&pid=700155&user=amanguptarkg6)

##### C++
```c++
class Solution{
    public:
    void mirror(Node* node){
        if(node == NULL) return;
        mirror(node->left);
        mirror(node->right);
        swap(node->left, node->right);
    }
};
```