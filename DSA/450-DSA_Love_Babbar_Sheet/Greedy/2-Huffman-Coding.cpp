// Question: https://practice.geeksforgeeks.org/problems/huffman-encoding/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=d3cb352854ac36020a4aaf2bf2b320a1&pid=1934&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value; char ch;
    struct Node *left = NULL, *right = NULL;
    
    Node(char chr, int val){
        left = right = NULL;
        this->ch = chr;
        this->value = val;
    }
};

struct compare{
    bool operator()(struct Node *left,struct Node* right){
        return (left->value > right->value);
    }
};

void preorder(struct Node* ptr, string s){
    if(ptr->left==NULL && ptr->right==NULL){
        cout << s << " ";
        return;
    }
    
    if( ptr->left != NULL ) preorder(ptr->left, s + '0');
    if( ptr->right != NULL ) preorder(ptr->right, s + '1');
}

int main() {
	
	int tests; cin>>tests;
	while(tests-->0){
	    
	    priority_queue< Node*, vector<Node*>, compare> tree;
	    
	    int val;
	    string s; cin>>s;
	    for(int i=0;i<(int)s.size();i++){
	        cin>>val;
	        struct Node* temp = new Node(s[i], val);
	        tree.push(temp);
	    }
	    
	    while(tree.size()>1){
	        struct Node* a = tree.top(); tree.pop();
	        struct Node* b = tree.top(); tree.pop();
	        
	        struct Node* temp = new Node('*', a->value + b->value);
	        temp->left = a;
	        temp->right = b;
	        tree.push(temp);
	    }
	    
	    struct Node* root = tree.top();
	    preorder(root, "");
	    
	    cout<<endl;
	}
	
	return 0;
}