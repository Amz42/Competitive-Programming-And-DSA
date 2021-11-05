### GeeksForGeeks - Merge two BST's

[Question](https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1/)
| [Solution-1](https://practice.geeksforgeeks.org/viewSol.php?subId=6acd259761abb12d0bfb242edfcd7a61&pid=700440&user=amanguptarkg6)
| [Solution-2](https://practice.geeksforgeeks.org/viewSol.php?subId=59914e8824109ef75e60f903e8184aea&pid=700440&user=amanguptarkg6)

#### C++

##### Solution - 1
```c++
// Time Complexity: O(n+m)
// Space Complexity: O(n+m)

class Solution{
    void traverse(Node* root, vector<int>& v){
        if(!root) return;
        traverse(root->left, v);
        v.push_back(root->data);
        traverse(root->right, v);
    }
    public:
    // Return a integer of integers having all the nodes in both the BSTs in a sorted order.
    vector<int> merge(Node *root1, Node *root2){
        vector<int> A,B,answer;
        traverse(root1, A);
        traverse(root2, B);
        
        int i,j; i = j = 0;
        while(i<A.size() && j<B.size())
            answer.push_back((A[i] < B[j]) ? A[i++] : B[j++]);
        while(i<A.size())
            answer.push_back(A[i++]);
        while(j<B.size())
            answer.push_back(B[j++]);
        
        return answer;
    }
};
```

##### Solution - 2
```c++
// Time Complexity: O(n + m)
// Space Complexity: O(height of tree1 + height of tree2)

class Solution{
public:
    vector<int> merge(Node *r1, Node *r2){
        vector<int> answer;
        stack<Node*> s1, s2;
        
        while(r1 || r2 || s1.size() || s2.size()) {
            if(r1) s1.push(r1), r1 = r1->left;
            else if(r2) s2.push(r2), r2 = r2->left;
            else {
                if(s1.size() == 0) {
                    r2 = s2.top(); s2.pop();
                    answer.push_back(r2->data);
                    r2 = r2->right;
                } else if(s2.size() == 0) {
                    r1 = s1.top(); s1.pop();
                    answer.push_back(r1->data);
                    r1 = r1->right;
                } else {
                    r1 = s1.top();
                    r2 = s2.top();
                    if(r1->data < r2->data) {
                        s1.pop();
                        answer.push_back(r1->data);
                        r1 = r1->right;
                        r2 = NULL;
                    } else {
                        s2.pop();
                        answer.push_back(r2->data);
                        r2 = r2->right;
                        r1 = NULL;
                    }
                }
            }
        }
        
        return answer;
    }
};
```