### GeeksForGeeks - Maximum Width of Tree

[Question](https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=8af40e88d6a3302fabdc948655c3770b&pid=700159&user=amanguptarkg6)

##### C++
```c++
class Solution {
public:
    int getMaxWidth(Node* root) {
        int answer = 0;
        queue<Node*> q; q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            answer = max(answer, n);
            
            while(n--){
                Node* node = q.front(); q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        
        return answer;
    }
};
```