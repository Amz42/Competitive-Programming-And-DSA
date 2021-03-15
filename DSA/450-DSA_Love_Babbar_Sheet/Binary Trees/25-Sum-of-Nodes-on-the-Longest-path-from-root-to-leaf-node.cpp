// Question: https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=557b465bd34eb93a6ca0209c62d6c066&pid=700680&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;	
	Node(int x){
	    data = x;
	    left = right = NULL;
	}
};

int sumOfLongRootToLeafPath(Node* root);

int main(){
    int t; scanf("%d", &t);
    while (t--){
        map<int, Node*> m;
        int n;
        scanf("%d",&n);
        struct Node *root = NULL;
        struct Node *child;
        while (n--){
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end()){
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL) root = parent;
            }else parent = m[n1];
            child = new Node(n2);
            
            if (lr == 'L') parent->left = child;
            else parent->right = child;
            m[n2]  = child;
        }
        cout<<sumOfLongRootToLeafPath(root)<<endl;
    }
    
    return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/

// your task is to complete this function

pair<int,int> traverse(Node* n){
    if(n == NULL) return make_pair(0,0);
    auto k = max(traverse(n->left) , traverse(n->right));
    k.first++;
    k.second += n->data;
    return k;
}

int sumOfLongRootToLeafPath(Node* root){
	return (traverse(root)).second;
}