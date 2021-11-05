### GeeksForGeeks - Find a pair with given target in BST

[Question](https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1/#)
| [Solution-1](https://practice.geeksforgeeks.org/viewSol.php?subId=a0dc11a52dde54878761f75f5af02409&pid=700550&user=amanguptarkg6)
| [Solution-2](https://practice.geeksforgeeks.org/viewSol.php?subId=0c132c55ddd7deebf5aba793fcfd36d4&pid=700550&user=amanguptarkg6)

#### C++

##### Solution-1 (Converting BST to Doubly Link List | Tree Modification)
```c++
// Time Complexity: O(n)
// Space Complexity: O(height of BST)

class Solution{
    void convertBSTtoLL(Node* node, Node** head, Node** tail){
        if(node == NULL) return;
        
        convertBSTtoLL(node->left, head, tail);
        
        node->left = *tail;
        if(*tail)
            (*tail)->right = node;
        else
            *head = node;
        *tail = node;
        
        convertBSTtoLL(node->right, head, tail);
    }
public:
    int isPairPresent(struct Node *root, int target){
        Node *head = NULL, *tail = NULL;
        convertBSTtoLL(root, &head, &tail);
        
        while(head->data < tail->data){
            int sum = head->data + tail->data;
            if(sum == target)
                return 1;
            else if(sum < target)
                head = head->right;
            else
                tail = tail->left;
        }
        
        return 0;
    }
};
```

##### Solution-2 (Without Tree Modification)
```c++
// Time Complexity: O(n)
// Space Complexity: O(height of tree)

class Solution{
public:
    void left(Node* root, stack<Node*> &s) {
        while(root) s.push(root), root = root->left;
    }
    void right(Node* root, stack<Node*> &s) {
        while(root) s.push(root), root = root->right;
    }
    
    int isPairPresent(struct Node *root, int target) {
        stack<Node*> s1, s2;
        
        left(root, s1);
        right(root, s2);
        
        while(!s1.empty() && !s2.empty()){
            Node* a = s1.top();
            Node* b = s2.top();
            
            if(a->data + b->data < target) {
                s1.pop();
                left(a->right, s1);
            } else if(a->data + b->data > target) {
                s2.pop();
                right(b->left, s2);
            } else
                return 1;
        }
        
        return 0;
    }
};
```