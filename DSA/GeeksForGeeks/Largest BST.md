### GeeksForGeeks - Largest BST

[Question](https://practice.geeksforgeeks.org/problems/largest-bst/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=a7c98a4433071488a193772f0fc08079&pid=700351&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(height of BST)

struct Info{
    bool isBST;
    int size, mn, mx;
    Info(bool BST, int siz, int mnn, int mxx){
        isBST = BST;
        size = siz;
        mn = mnn;
        mx = mxx;
    }
};

Info BstCheck(Node* root){
    Info g = *new Info(true, 0, INT_MAX, INT_MIN);
    if(!root) return g;
    
    Info l = BstCheck(root->left);
    Info r = BstCheck(root->right);
    
    if(l.isBST && r.isBST && l.mx < root->data && root->data < r.mn){
        g.isBST = true;
        g.size = l.size + 1 + r.size;
        g.mn = min(l.mn, root->data);
        g.mx = max(r.mx, root->data);
    }else{
        g.isBST = false;
        g.size = max(l.size, r.size);
        g.mn = g.mx = -1;
    }
    
    return g;
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root){
    Info rt = BstCheck(root);
	return rt.size;
}
```