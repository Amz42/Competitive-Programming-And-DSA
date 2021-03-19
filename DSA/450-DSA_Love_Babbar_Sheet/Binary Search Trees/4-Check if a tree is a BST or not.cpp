// Question: https://practice.geeksforgeeks.org/problems/check-for-bst/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=77bc1ef59a9b338d996991b23e5bf07a&pid=700149&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




 // } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// return true if the given tree is a BST, else return false
class Solution{
    public:
    bool BST;
    
    pair<int,int> check(Node* root){
        if(!root->left && !root->right)
            return make_pair(root->data, root->data);
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        if(root->left){
            auto l = check(root->left);
            mn = min(mn, l.first);
            mx = max(mx, l.second);
            if(l.second >= root->data) BST = false;
        }
        
        if(root->right){
            auto r = check(root->right);
            mn = min(mn, r.first);
            mx = max(mx, r.second);
            if(r.first <= root->data) BST = false;
        }
        
        mn = min(mn, root->data);
        mx = max(mx, root->data);
        
        return make_pair(mn, mx);
    }
    
    bool isBST(Node* root){
        BST = true;
        check(root);
        return BST;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////



// { Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    if(ob.isBST(root)) 
        cout<<"1\n";
        
    else
        cout<<"0\n";
   }
   return 0;
}


//Position this line where user code will be pasted
  // } Driver Code Ends