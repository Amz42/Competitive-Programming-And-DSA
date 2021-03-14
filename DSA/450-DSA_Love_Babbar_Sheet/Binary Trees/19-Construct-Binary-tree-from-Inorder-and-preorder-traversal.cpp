// Question: https://practice.geeksforgeeks.org/problems/construct-tree-1/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=2c1b347d434d80d3f681dd283a6b2630&pid=700586&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *buildTree(int inorder[], int preorder[], int n);
void printPostOrder(Node *root){
	if(root==NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main(){
	int t; cin>>t; while(t--){
		int n; cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++) cin>> inorder[i];
		for(int i=0; i<n; i++) cin>> preorder[i];
		
		Node *root = buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

/*Complete the code here.
Node is as follows:
struct Node{
    int data;
    Node* left, right;
};
*/
unordered_map<int,int> mp;
int idx;
Node* solve(int in[], int pre[], int l, int r){
    if(l>r) return NULL;
    
    Node* p = new Node(pre[idx++]);
    p->left = solve(in, pre, l, mp[p->data]-1);
    p->right = solve(in, pre, mp[p->data]+1, r);
    
    return p;
}

Node* buildTree(int in[],int pre[], int n){
    idx = 0; mp.clear();
    for(int i=0;i<n;i++) mp[in[i]] = i;
    Node* root = solve(in, pre, 0, n-1);
    return root;
}