## [Check if all levels of two trees are anagrams or not](https://www.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1)

#### Solution 1: C++ - Level order traversal & unordered map
```c++
class Solution{
public:
    bool areAnagrams(Node *root1, Node *root2) {
        queue<Node*> q1, q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() && !q2.empty()) {
            
            unordered_map<int, int> mp;
            
            int n1 = q1.size();
            for(int i=0; i<n1; i++) {
                Node* node = q1.front(); q1.pop();
                mp[node->data]++;
                
                if(node->left != nullptr) q1.push(node->left);
                if(node->right != nullptr) q1.push(node->right);
            }
            
            int n2 = q2.size();
            for(int i=0; i<n2; i++) {
                Node* node = q2.front(); q2.pop();
                
                if(mp[node->data] == 0) return false;
                else mp[node->data]--;
                
                if(node->left != nullptr) q2.push(node->left);
                if(node->right != nullptr) q2.push(node->right);
            }
            
            if(n1 != n2) return false;
        }
        
        return (q1.empty() && q2.empty());
    }
};
```