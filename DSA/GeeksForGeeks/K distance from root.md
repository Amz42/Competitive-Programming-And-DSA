### GeeksForGeeks - K distance from root

[Question](https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=3c5819ac8ee56bf958f2e4c49478142e&pid=700154&user=amanguptarkg6)

##### C++
```c++
void fun(Node* node, vector<int>& answer, int& k, int dist){
    if(node == NULL) return;
    if(dist == k){
        answer.push_back(node->data);
        return;
    }
    
    fun(node->left, answer, k, dist + 1);
    fun(node->right, answer, k, dist + 1);
}

vector<int> Kdistance(struct Node *root, int k){
    vector<int> answer;
    fun(root, answer, k, 0);
    return answer;
}
```