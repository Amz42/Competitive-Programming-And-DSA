// Question: https://practice.geeksforgeeks.org/problems/median-of-bst/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=48202efe556bf3ca49d585dbdbd4c175&pid=700628&user=amanguptarkg6

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



float findMedian(struct Node* node);

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
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/*
Structure of the binary Search Tree is as
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

void traverse(Node* root, int& count){
    if(!root) return;
    
    count++;
    traverse(root->left, count);
    traverse(root->right, count);
}

void Kth(Node* root, float& median, int& count, int& i){
    if(!root) return;
    Kth(root->left, median, count, i);
    i++;
    if(
        (count&1 && i == count/2+1) ||
        (count%2==0 && (i==count/2 || i == count/2+1))
    ) median += root->data;
    Kth(root->right, median, count, i);
}

// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node *root){
    int count = 0;
    traverse(root, count);
    
    float median = 0; int i = 0;
    Kth(root, median, count, i);
    if(count%2==0) median /= 2;
    return median;
}


