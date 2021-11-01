### GeeksForGeeks - Diagonal Sum In Binary Tree

[Question](https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=ad9695dbe6eacd24e8245c7bb5d5267d&pid=700619&user=amanguptarkg6)

##### C++
```c++
void fun(Node* node, int diag,vector<int>& answer){
    if(node == NULL) return;
    if(answer.size() <= diag)
        answer.push_back(0);
    
    answer[diag] += node->data;
    
    fun(node->left, diag + 1, answer);
    fun(node->right, diag, answer);
}

vector <int> diagonalSum(Node* root) {
    vector<int> answer;
    fun(root, 0, answer);
    return answer;
}
```