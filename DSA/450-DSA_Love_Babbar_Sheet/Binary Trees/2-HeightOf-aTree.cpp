// Question: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a7b5a8a23d316115d05cd7a534009ef1&pid=700164&user=amanguptarkg6

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N') return NULL;
    
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str;) ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node*> queue; queue.push(root);
        
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
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


//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
//////////////////////////////////////////////////////////////////////////////////////////////
class Solution{
    public:
    int answer = 0;
    void traverse(struct Node* node, int height){
        answer = max(answer, height);
        if(node->left!=NULL) traverse(node->left, height+1);
        if(node->right!=NULL) traverse(node->right, height+1);
    }
    
    int height(struct Node* node){
        // code here 
        traverse(node, 1);
        return answer;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////

// { Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
        Solution ob;
		cout<<ob.height(root)<<endl;
    }
    return 0;
}  // } Driver Code Ends