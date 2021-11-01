### GeeksForGeeks - ZigZag Tree Traversal

[Question](https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=1fd52dcb91ed246aff06fd8d979a8980&pid=700688&user=amanguptarkg6)

##### C++
```c++
vector <int> zigZagTraversal(Node* root){
	queue<Node*> q; q.push(root);
	
	vector<int> answer;
	
	int level = 0;
	while(!q.empty()){
	    int n = q.size();
	    vector<int> v;
	    while(n--){
	        auto k = q.front(); q.pop();
	        v.push_back(k->data);
	        
	        if(k->left) q.push(k->left);
	        if(k->right) q.push(k->right);
	    }
	    
	    if(level&1) reverse(v.begin(),v.end());
	    
	    for(auto k: v) answer.push_back(k);
	    level++;
	}
	
	return answer;
}
```