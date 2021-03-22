// Question: https://practice.geeksforgeeks.org/problems/largest-bst/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a7c98a4433071488a193772f0fc08079&pid=700351&user=amanguptarkg6

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

int largestBst(Node *root);

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



int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

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