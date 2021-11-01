### GeeksForGeeks - Children Sum Parent

[Question](https://practice.geeksforgeeks.org/problems/children-sum-parent/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=dccf21cf62e983f5624c8d603a96fbe7&pid=700618&user=amanguptarkg6)

##### C++
```c++
class Solution{
    bool answer;
    int fun(Node* node){
        if(node == NULL)
            return 0;
        if(node->left == NULL && node->right == NULL)
            return node->data;
        
        int left = fun(node->left);
        int right = fun(node->right);
        
        answer &= (left + right == node->data);
        return node->data;
    }
public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root){
        answer = true;
        fun(root);
        return answer ? 1 : 0;
    }
};
```