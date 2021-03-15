// Question: https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=951caa8f9f04305a2cf88179d49dd833&pid=700647&user=amanguptarkg6

//Initial Template for C++

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

void printAllDups(Node* root);

int main(){
  int t; scanf("%d\n", &t);
  struct Node *child;
  while (t--){
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     printAllDups(root);
     cout<<endl;
  }
  return 0;
}// } Driver Code Ends


//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line

unordered_map<string, int> mp;
string traverse(Node* n){
    string s = "";
    if(n==NULL) return s;
    
    s += to_string(n->data);
    s += "," + traverse(n->left);
    s += "," + traverse(n->right);
    
    mp[s]++;
    
    return s;
}

void printAllDups(Node* root){
    mp.clear();
    traverse(root);
    
    vector<string> answer;
    for(auto k: mp){
        if(k.second>1){
            int i = 0; string s = "";
            while(k.first[i]!=',') s += k.first[i++];
            answer.push_back(s);
        }
    }
    
    if(answer.size() == 0) cout<<"-1";
    else{
        sort(answer.begin(), answer.end());
        for(auto k: answer) cout << k << " ";
    }
}