### GeeksForGeeks - Fixing Two nodes of a BST

[Question](https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=9514830fc6b611e2659f51e0636b35eb&pid=700552&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(height of tree)

class Solution {
    void swap(int* a, int* b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void fun(
        struct Node* node, struct Node** prev,
        struct Node** first, struct Node** middle, struct Node** last
    ){
        if(node == NULL) return;
        
        fun(node->left, prev, first, middle, last);
        
        if(*prev && (*prev)->data > node->data){
            if(*first == NULL)
                *first = *prev,
                *middle = node;
            else
                *last = node;
        }
        
        *prev = node;
        
        fun(node->right, prev, first, middle, last);
    }
public:
    void correctBST( struct Node* root ){
        struct Node *prev, *first, *middle, *last;
        prev = first = middle = last = NULL;
        
        fun(root, &prev, &first, &middle, &last);
        
        if(first && last)
            swap(&(first->data), &(last->data));
        else if(first && middle)
            swap(&(first->data), &(middle->data));
    }
};
```