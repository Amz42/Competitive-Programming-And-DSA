// Question: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a1d3cdec275f632c83b60d77c7c6cb03&pid=700160&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node{
    int data;
    Node* left; Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


vector <int> bottomView(Node *root);

Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; ) ip.push_back(str);

    Node* root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

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

int main() {
    int t; string tc; getline(cin, tc);
    t = stoi(tc); while(t--){
        string s ,ch; getline(cin, s);
        Node* root = buildTree(s);
        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Method that returns the bottom view.
vector <int> bottomView(Node *root){
    vector<int> answer;
    if(root == NULL) return answer;
    queue<pair<Node*, int>> q; q.push(make_pair(root, 0));
    map<int,int> mp;
    
    while(!q.empty()){
        auto k = q.front(); q.pop();
        Node *node = k.first;
        mp[k.second] = node->data;
        
        if(node->left != NULL) q.push(make_pair(node->left, k.second-1));
        if(node->right != NULL) q.push(make_pair(node->right, k.second+1));
    }
    
    
    for(auto k: mp) answer.push_back(k.second);
    return answer;
}