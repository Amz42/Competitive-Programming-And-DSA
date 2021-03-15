// Question: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=727ad6a0d110fa66a0a41aa8a6eb1f2d&pid=700221&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

 // } Driver Code Ends
/* A binary tree node

struct Node{
    int data;
    struct Node* left, right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/
class Solution{
    public:
    Node* answer;
    int A, B;
    
    int traverse(Node* n){
        if(n==NULL) return 0;
        
        int left = traverse(n->left);
        int right = traverse(n->right);
        
        if(n->data == A || n->data == B){
            if(left || right){
                answer = n;
                return 0;
            }
            return 1;
        }
        
        if(left && right){
            answer = n;
            return 0;
        }
        
        return (left || right);
    }
    
    Node* lca(Node* root , int n1 , int n2){
        answer = NULL;
        A = n1; B = n2;
        traverse(root);
        return answer;
    }
};

// { Driver Code Starts.

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str){
    // Corner Case
    if(str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str;) ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
    // Push the root to the queue
    queue<Node*> queue; queue.push(root);

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
            currNode->left = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root){
    if(!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int t; scanf("%d",&t); while(t--){
        int a,b; scanf("%d %d ",&a,&b);
        string s; getline(cin,s);
        Node* root = buildTree(s);
        Solution ob; cout << ob.lca(root,a,b)->data << endl;
    }
    return 0;
}
  // } Driver Code Ends