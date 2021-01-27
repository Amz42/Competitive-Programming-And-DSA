// Question: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=43f191e624e1de23edd497a92ed5e62b&pid=700166&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left; struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val; temp->left = NULL; temp->right = NULL;
    return temp;
}
// Function to Build Tree
Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; ) ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue; queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size()) break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
bool isBalanced(Node *root);
int main(){
    int t; scanf("%d ",&t); while(t--){
        string s; getline(cin,s);
        Node* root = buildTree(s); cout << isBalanced(root) << endl;
    }
    return 1;
}

bool balanced;

int fun(Node* node){
    if(node == NULL) return 0;
    int left = fun(node->left);
    int right = fun(node->right);
    if(abs(left-right)>1) balanced = false;
    return (1 + max(left, right));
}

bool isBalanced(Node *root){
    balanced = true;
    fun(root);
    return balanced;
}