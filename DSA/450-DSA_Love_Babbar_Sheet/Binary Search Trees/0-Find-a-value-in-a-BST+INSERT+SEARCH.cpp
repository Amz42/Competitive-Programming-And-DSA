// Article: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
// INSERT Question: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// INSERT Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f8c47208cd1f13331ae198b915b8e7ce&pid=700216&user=amanguptarkg6
// SEARCH Question: https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1
// SEARCH Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=cdd47af70cdc6f558b1940b35ac596dc&pid=700349&user=amanguptarkg6

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node* root, int x);
Node* insert(Node* root, int Key);
// Node *insert(Node *tree, int val)
// {
//     Node *temp = NULL;
//     if (tree == NULL)
//         return new Node(val);

//     if (val < tree->data)
//     {
//         tree->left = insert(tree->left, val);
//     }
//     else if (val > tree->data)
//     {
//         tree->right = insert(tree->right, val);
//     }
    
//     return tree;
// }

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            root = insert(root, k);

        }

        int s;
        cin>>s;
        
     cout<<search(root,s);
     cout<<endl;
    }
}

// } Driver Code Ends


/* Node structure 

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

/*You are required to complete this method*/
bool search(Node* root, int x){
    if(root == NULL) return false;
    else if(root->data == x) return true;
    else if(root->data < x) return search(root->right, x);
    else return search(root->left, x);
}
Node* insert(Node* root, int Key){
    if(root == NULL)            return (new Node(Key));
    else if(root->data < Key)   root->right = insert(root->right, Key);
    else if(root->data > Key)   root->left = insert(root->left, Key);
    return root;
}