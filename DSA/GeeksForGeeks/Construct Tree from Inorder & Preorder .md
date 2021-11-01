### GeeksForGeeks - Construct Tree from Inorder & Preorder

[Question](https://practice.geeksforgeeks.org/problems/construct-tree-1/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=235e42081215bac27e79a10f19e7b6ff&pid=700586&user=amanguptarkg6)

##### C++
```c++
class Solution{
    unordered_map<int,int> mp;
    int i;
    Node* fun(int pre[], int l, int r){
        if(l > r) return NULL;
        
        Node* node = new Node(pre[i++]);
        node->left = fun(pre, l, mp[node->data] - 1);
        node->right = fun(pre, mp[node->data] + 1, r);
        return node;
    }
public:
    Node* buildTree(int in[],int pre[], int n){
        i = 0; mp.clear();
        for(int i=0;i<n;i++) mp[in[i]] = i;
        return fun(pre, 0, n-1);
    }
};
```