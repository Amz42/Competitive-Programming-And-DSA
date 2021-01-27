// Question: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=239a8c3df44849259a95a9139ad9514e&pid=700153&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> rightView(struct Node *root);

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = rightView(root);
        for(int x : vec){
            cout<<x<<" ";
        }
        cout << endl;
    }
    return 0;
}

//////////////////////////////////////////////////////////////////// Solution 1: recursive
void Right_View_of_Binary_Tree(Node* node, vector<int> &v, int height){
    if(node==NULL) return;
    if(v.size()<height) v.push_back(node->data);
    
    Right_View_of_Binary_Tree(node->right, v, height + 1);
    Right_View_of_Binary_Tree(node->left, v, height + 1);
}

vector<int> rightView(Node *root){
   vector<int> v;
   Right_View_of_Binary_Tree(root, v, 1);
   return v;
}

//////////////////////////////////////////////////////////////////// Solution 2: iterative
vector<int> rightView(Node *root){
    vector<int> ans;
    if(!root) return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(q.size()){
        int n=q.size();

        for(int i=1;i<=n;i++){
            Node *temp = q.front();
            q.pop();
            if(i==n) ans.push_back(temp->data);
            
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        
    }
    return ans;
}