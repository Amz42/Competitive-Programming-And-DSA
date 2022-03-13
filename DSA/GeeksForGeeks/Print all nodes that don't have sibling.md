## GeeksForGeeks - Print all nodes that don't have sibling

### [Question](https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1#)

### [C++ Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=6ee7351b37248b31737be75e589eb2c7&pid=700228&user=amanguptarkg6)
```c++
void findNoSiblingNodes(Node* node, vector<int>& answer){
    if(node == NULL) return;
    
    if(node->left != NULL && node->right == NULL)
        answer.push_back(node->left->data);
    if(node->left == NULL && node->right != NULL)
        answer.push_back(node->right->data);
    
    findNoSiblingNodes(node->left, answer);
    findNoSiblingNodes(node->right, answer);
}

vector<int> noSibling(Node* node){
    vector<int> answer;
    findNoSiblingNodes(node, answer);
    sort(answer.begin(), answer.end());
    if(answer.size() == 0)
        answer.push_back(-1);
    return answer;
}
```

### [Java Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=8011c876b3c63ed10cd8668674899f94&pid=700228&user=amanguptarkg6)
```java
class Tree {
    private ArrayList<Integer> answer = new ArrayList();
    private void findNoSiblingNodes(Node node) {
        if(node == null)
            return;
        if(node.left != null && node.right == null)
            answer.add(node.left.data);
        if(node.left == null && node.right != null)
            answer.add(node.right.data);
        
        findNoSiblingNodes(node.left);
        findNoSiblingNodes(node.right);
        return;
    }
    
    ArrayList<Integer> noSibling(Node node) {
        findNoSiblingNodes(node);
        Collections.sort(answer);
        
        if(answer.size() == 0)
            answer.add(-1);
        return answer;
    }
}
```