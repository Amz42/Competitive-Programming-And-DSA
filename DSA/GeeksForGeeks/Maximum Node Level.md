### GeeksForGeeks - Maximum Node Level

[Question](https://practice.geeksforgeeks.org/problems/maximum-node-level/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=ea5cc068c3d555638dbc1e8a01c07670&pid=700616&user=amanguptarkg6)

##### C++
```c++
int maxNodeLevel(Node *root){
    int answer = 0, nodes = 0;
    queue<Node*> q; q.push(root);
    
    int lvl = 0;
    while(!q.empty()){
        int n = q.size();
        if(n > nodes)
            nodes = n, answer = lvl;
        
        while(n--){
            Node* node = q.front(); q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
        
        lvl++;
    }
    
    return answer;
}
```