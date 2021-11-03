### GeeksForGeeks - Median of BST

[Question](https://practice.geeksforgeeks.org/problems/median-of-bst/1/#)
| [Solution-1](https://practice.geeksforgeeks.org/viewSol.php?subId=0bb58fa4f079e6bafb18259c82933d89&pid=700628&user=amanguptarkg6)
| [Solution-2 (Morris Inorder Traversal)](https://practice.geeksforgeeks.org/viewSol.php?subId=b01b80a3225f940bfade607706964fdd&pid=700628&user=amanguptarkg6)

#### C++

##### Solution - 1
```c++
// Time Complexity: O(n)
// Space Complexity: O(height of tree)

void fun1(Node* node, int& n){
    if(node == NULL) return;
    n++;
    fun1(node->left, n);
    fun1(node->right, n);
}

void fun2(Node* node, long& sum, int& n, int& i){
    if(node == NULL) return;
    fun2(node->left, sum, n, i);
    
    if(
        (n%2 == 1 && i == n / 2) ||
        (n%2 == 0 && (i == n / 2 - 1 || i == n / 2))
    ) sum += node->data;
    
    i++;
    
    fun2(node->right, sum, n, i);
}

float findMedian(struct Node *root){
    int n = 0, i = 0;
    fun1(root, n);
    long answer = 0;
    fun2(root, answer, n, i);
    
    return n&1 ? answer : answer / 2.0;
}
```

##### Solution-2 (Morris Inorder Traversal)
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

int MorrisCount(Node* root){
    int n = 0;
    Node* curr = root;
    
    while(curr){
        if(curr->left == NULL){
            n++;
            curr = curr->right;
        } else {
            Node* predecessor = curr->left;
            while(predecessor->right != NULL && predecessor->right != curr)
                predecessor = predecessor->right;
            
            if(predecessor->right == curr){
                n++;
                predecessor->right = NULL;
                curr = curr->right;
            }else{
                predecessor->right = curr;
                curr = curr->left;
            }
        }
    }
    
    return n;
}

float MorrisMedian(Node* root, int n){
    int i = 0, answer = 0;
    Node* curr = root;
    
    while(curr){
        if(curr->left == NULL){
            i++;
            
            if(
                ( (n%2 == 1) && (n + 1) / 2 == i ) || 
                ( (n%2 == 0) && (n/2 == i || n/2 + 1 == i))
            ) answer += curr->data;
            
            curr = curr->right;
        } else {
            Node* predecessor = curr->left;
            while(predecessor->right != NULL && predecessor->right != curr)
                predecessor = predecessor->right;
            
            if(predecessor->right == curr){
                i++;
                
                if(
                    ( (n%2 == 1) && (n + 1) / 2 == i ) || 
                    ( (n%2 == 0) && (n/2 == i || n/2 + 1 == i))
                ) answer += curr->data;
                
                predecessor->right = NULL;
                curr = curr->right;
            } else {
                predecessor->right = curr;
                curr = curr->left;
            }
        }
    }
    
    return n&1 ? answer : answer / 2.0;
}


float findMedian(struct Node *root){
    int n = MorrisCount(root);
    return MorrisMedian(root, n);
}
```