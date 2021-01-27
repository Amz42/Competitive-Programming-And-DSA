// Question: https://practice.geeksforgeeks.org/problems/level-order-traversal/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=29d68c12cb13eac830e2d51f8d494f6e&pid=700511&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;    
    return temp;
}
vector<int> levelOrder(struct Node* node);

void inOrder(struct Node* node){
  if (node == NULL) return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}

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

/* Driver program to test size function*/
int main(){
  int t; scanf("%d ",&t);
  while (t--){
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}

//You are required to complete this method
vector<int> levelOrder(Node* node){
  //Your code here
  queue<struct Node*> q;
  q.push(node);
  vector<int> answer;
  
  while(!q.empty()){
      struct Node* ptr = q.front(); q.pop();
      answer.push_back(ptr->data);
      if(ptr->left!=NULL) q.push(ptr->left);
      if(ptr->right!=NULL) q.push(ptr->right);
  }
  
  return answer;
}