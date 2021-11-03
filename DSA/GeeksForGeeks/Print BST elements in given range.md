### GeeksForGeeks - Print BST elements in given range

[Question](https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1/#)
| [Solution-1](https://practice.geeksforgeeks.org/viewSol.php?subId=b6e571c904332b2fb872a8a07f823fcf&pid=700249&user=amanguptarkg6)
| [Solution-2](https://practice.geeksforgeeks.org/viewSol.php?subId=70c5357466a4a65f5ac2b9e086bc21eb&pid=700249&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(Height of the BST)

class Solution1 {
    void fun(Node* node, int& low, int& high, vector<int>& answer){
        if(node == NULL) return;
        
        fun(node->left, low, high, answer);
        if(low <= node->data && node->data <= high)
            answer.push_back(node->data);
        fun(node->right, low, high, answer);
    }
  public:
    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> answer;
        fun(root, low, high, answer);
        return answer;
    }
};

class Solution2 {
    void fun(Node* node, int& low, int& high, vector<int>& answer){
        if(node == NULL) return;
        
        if(!(node->data <= low))
            fun(node->left, low, high, answer);
        if(low <= node->data && node->data <= high)
            answer.push_back(node->data);
        if(!(node->data >= high))
            fun(node->right, low, high, answer);
    }
  public:
    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> answer;
        fun(root, low, high, answer);
        return answer;
    }
};
```