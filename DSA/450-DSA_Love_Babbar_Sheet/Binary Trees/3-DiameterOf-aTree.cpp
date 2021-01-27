// Question: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=c69dea25f8edeb470173504a026680d6&pid=700165&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N') return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front(); queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
int diameter(struct Node* tree);
int main() {
    int t; scanf("%d\n", &t); while (t--) {
        string s; getline(cin, s);
        Node* root = buildTree(s);
        cout << diameter(root) << endl;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////// MAIN ANSWER
int height(Node *node){
    if(node==NULL) return 0;
    return (1 + max(height(node->left), height(node->right)));
}

int diameter(Node* root) {
    if(root == NULL) return 0;
    return max({
        // if max path goes through this node
        height(root->left) + height(root->right) + 1,
        // if max path is present in left sub-tree
        diameter(root->left),
        // if max path is present in left sub-tree
        diameter(root->right)
    });
}