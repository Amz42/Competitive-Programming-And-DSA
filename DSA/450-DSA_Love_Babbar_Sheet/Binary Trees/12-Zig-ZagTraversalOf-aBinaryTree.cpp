// Question: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=1fd52dcb91ed246aff06fd8d979a8980&pid=700688&user=amanguptarkg6

//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left; Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N') return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; ) ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector <int> zigZagTraversal(Node* root);
int main(){
    int t; scanf("%d ",&t);
    while (t--){
        string s; getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}

// return a vector containing the zig zag level order traversal of the given tree
vector <int> zigZagTraversal(Node* root){
	queue<Node*> q; q.push(root);
	
	vector<int> answer;
	
	int level = 0;
	while(!q.empty()){
	    int n = q.size();
	    vector<int> v;
	    while(n--){
	        auto k = q.front(); q.pop();
	        v.push_back(k->data);
	        
	        if(k->left) q.push(k->left);
	        if(k->right) q.push(k->right);
	    }
	    
	    if(level&1) reverse(v.begin(),v.end());
	    for(auto k: v) answer.push_back(k);
	    level++;
	}
	
	return answer;
}