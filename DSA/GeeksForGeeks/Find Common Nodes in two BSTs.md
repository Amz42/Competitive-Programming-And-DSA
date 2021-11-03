### GeeksForGeeks - Find Common Nodes in two BSTs

[Question](https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1/)
| [Solution-1](https://practice.geeksforgeeks.org/viewSol.php?subId=f1028ce28fb10400162440aec25a9993&pid=700500&user=amanguptarkg6)
| [Solution-2](https://practice.geeksforgeeks.org/viewSol.php?subId=da2ef102e71d68a3edf130737e6d6ebf&pid=700500&user=amanguptarkg6)

#### C++

##### Solution-1
```c++
// Time Complexity: O(n1 + n2)
// Space Complexity: O(n1 + n2)

class Solution1{
    void fun(Node* node, vector<int>& v){
        if(node == NULL) return;
        fun(node->left, v);
        v.push_back(node->data);
        fun(node->right, v);
    }
public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2){
        vector<int> a, b;
        fun(root1, a);
        fun(root2, b);
        
        int i = 0, j = 0;
        vector<int> answer;
        
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                answer.push_back(a[i]);
                i++, j++;
            }else if(a[i] < b[j]) i++;
            else j++;
        }
        
        return answer;
    }
};
```

##### Solution-2
```c++
// Time Complexity: (n1 + n2)
// Space Complexity: (h1 + h2)

class Solution{
public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *r1, Node *r2){
        vector<int> answer;
        stack<Node*> s1, s2;
        
        while(true){
            if(r1){
                s1.push(r1);
                r1 = r1->left;
            } else if(r2) {
                s2.push(r2);
                r2 = r2->left;
            } else if(s1.size() && s2.size()) {
                r1 = s1.top();
                r2 = s2.top();
                
                if(r1->data == r2->data){
                    s1.pop(); s2.pop();
                    answer.push_back(r1->data);
                    r1 = r1->right;
                    r2 = r2->right;
                } else if(r1->data < r2->data) {
                    s1.pop();
                    r1 = r1->right;
                    r2 = NULL;
                } else {
                    s2.pop();
                    r2 = r2->right;
                    r1 = NULL;
                }
            } else
                break;
        }
        
        return answer;
    }
};
```