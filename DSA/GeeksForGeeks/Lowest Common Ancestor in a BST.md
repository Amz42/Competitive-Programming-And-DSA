### GeeksForGeeks - Lowest Common Ancestor in a BST

[Question](https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=3d56a37e47f83627d61f6671c0040900&pid=700236&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(Height of the BST)
// Space Complexity: O(Height of the BST)
Node* LCA(Node *root, int n1, int n2){
   char f1,f2;
   while(true){
       if(root->data == n1 || root->data == n2) return root;
       f1 = (root->data > n1 ? 'L' : 'R' );
       f2 = (root->data > n2 ? 'L' : 'R' );
       
       if(f1!=f2) return root;
       root = (f1 == 'L' ?  root->left : root->right );
   }
}

// Logic:
// SEARCH for both keys at same time
// if search goes in opposite direction for the keys
//      then current node is LCA
// else
//      keep moving in search direction
```