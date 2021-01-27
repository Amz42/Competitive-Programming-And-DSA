// Question: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=cb2a8aa606c5a001f5a2b7f3c464bc4e&pid=700174&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);
Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str;) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue; queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front(); queue.pop();

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

int main() {
    int t; scanf("%d ",&t); while(t--){
        string s; getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec) cout << x << " " << endl;
    }
    return 0;
}


//////////////////////////////////////////////////////////////////// Solution 1: recursive
void left_View_of_Binary_Tree(Node* node, vector<int>&v, int height){
    if(node==NULL) return;
    if(v.size()<height) v.push_back(node->data);
    
    left_View_of_Binary_Tree(node->left, v, height+1);
    left_View_of_Binary_Tree(node->right, v, height+1);
}

vector<int> leftView(Node *root){
   vector<int> v;
   left_View_of_Binary_Tree(root, v, 1);  
   return v;
}

//////////////////////////////////////////////////////////////////// Solution 2: iterative
vector<int> leftView(Node *root){
    vector<int> ans;
    if(!root) return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(q.size()){
        int n=q.size();

        for(int i=1;i<=n;i++){
            Node *temp = q.front();
            q.pop();
            if(i==1) ans.push_back(temp->data);
            
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        
    }
    return ans;
}