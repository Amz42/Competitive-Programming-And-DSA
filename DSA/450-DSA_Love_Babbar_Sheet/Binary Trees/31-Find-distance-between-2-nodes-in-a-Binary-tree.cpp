// Question: https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=938e05451152f6f3d73543f9c2656d12&pid=700224&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/

Node* LCA;
int A,B;
bool traverse(Node* n){
    if(n == NULL) return 0;
    
    int left = traverse(n->left);
    int right = traverse(n->right);
    
    if(n->data == A || n->data == B){
        if(left || right){
            LCA = n;
            return 0;
        }
        return 1;
    }
    
    if(left && right){
        LCA = n;
        return 0;
    }
    
    return (left || right);
}

int depthA, depthB;
void traverse2(Node* n, int depth){
    if(n == NULL) return;
    if(n->data == A) depthA = depth;
    if(n->data == B) depthB = depth;
    
    traverse2(n->left, depth+1);
    traverse2(n->right, depth+1);
}

int findDist(Node* root, int a, int b) {
    LCA = NULL; A = a; B = b;
    traverse(root);
    
    depthA = depthB = 0;
    traverse2(LCA, 0);
    
    return (depthA + depthB);
}