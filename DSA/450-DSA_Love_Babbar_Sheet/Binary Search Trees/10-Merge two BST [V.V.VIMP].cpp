// Article: https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/
// Question: https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6acd259761abb12d0bfb242edfcd7a61&pid=700440&user=amanguptarkg6

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



 // } Driver Code Ends
/* The structure of Node is

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

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

// { Driver Code Starts.
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

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends