### GeeksForGeeks - Two Mirror Trees

[Question](https://practice.geeksforgeeks.org/problems/two-mirror-trees/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=22b78df1b67072bcbffa94c5a97f8444&pid=700156&user=amanguptarkg6)

##### C++
```c++
class Solution{
    public:
    int areMirror(Node* a, Node* b) {
        if(a == NULL && b == NULL)
            return true;
        if((a != NULL ^ b != NULL) || (a->data != b->data))
            return false;
        
        return areMirror(a->left, b->right) && areMirror(a->right, b->left);
    }
};
```