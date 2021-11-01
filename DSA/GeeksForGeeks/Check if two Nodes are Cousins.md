### GeeksForGeeks - Check if two Nodes are Cousins

[Question](https://practice.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=b4692506215b6101667ea3affb37f7aa&pid=700684&user=amanguptarkg6)

##### C++
```c++
bool isCousins(Node *root, int a, int b){
    queue<pair<Node*, Node*>> q;
    q.push(make_pair(root, root));
    
    while(!q.empty()){
        Node *parA = NULL, *parB = NULL;
        
        int n = q.size();
        while(n--){
            auto e = q.front(); q.pop();
            
            if(e.first->data == a) parA = e.second;
            if(e.first->data == b) parB = e.second;
            
            if(e.first->left != NULL) q.push(make_pair(e.first->left, e.first));
            if(e.first->right != NULL) q.push(make_pair(e.first->right, e.first));
        }
        if(parA != NULL ^ parB != NULL)
            return false;
        
        if(parA != NULL && parB != NULL)
            return parA != parB;
    }
    
    return false;
}
```