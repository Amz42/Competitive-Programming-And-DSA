// Question: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a6ed499fc51a01a80bd5e7516f63044f&pid=700204&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


vector <int> printBoundary(Node *root);

Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str); for(string str; iss >> str;) ip.push_back(str);
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
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t; string tc; getline(cin, tc);
    t=stoi(tc); while(t--){
        string s ,ch; getline(cin, s);
        Node* root = buildTree(s);
        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

void left_boundary(struct Node* node ,vector<int> &v){
    if(node == NULL) return;
    
    // it's not a leaf node
    if(node->left || node->right) v.push_back(node->data);
    
    if(node->left) left_boundary(node->left, v);
    else if(node->right) left_boundary(node->right, v);
}

void leaf_Nodes(struct Node* node ,vector<int> &v){
    if(node == NULL) return;
    
    leaf_Nodes(node->left, v);
    // it's a leaf node
    if(node->left == NULL && node->right == NULL)
        v.push_back(node->data);
    leaf_Nodes(node->right, v);
}

void right_boundary(struct Node* node ,vector<int> &v){
    if(node == NULL) return;
    
    if(node->right) right_boundary(node->right, v);
    else if(node->left) right_boundary(node->left, v);
    
    // it's not a leaf node
    if(node->left || node->right) v.push_back(node->data);
}

vector <int> printBoundary(Node *root){
    vector<int> answer;
    if(root == NULL) return answer;
    
    answer.push_back(root->data);
    
    if(root->left == NULL && root->right == NULL) return answer;
    
    left_boundary(root->left, answer);
    leaf_Nodes(root, answer);
    right_boundary(root->right, answer);
    
    return answer;
}