// Question: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=8bcc64ec3f14c26d5192351b985575f6&pid=700490&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){data = x; left = NULL; right = NULL;}
};

void topView(struct Node *root);

int main(){
    int t; cin>>t; while(t--){
        int n,i,k; cin>>n; i=n;
        Node* root=NULL;
        queue <Node*> q;
        while(i>0){
            int a,b; char c; cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front(); q.pop();
            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
        topView(root);
    }
    return 0;
}

void topView(struct Node *root){
    if(root == NULL) return;
    queue<pair<Node*, int>> q; q.push(make_pair(root, 0));
    map<int,int> mp;
    
    while(!q.empty()){
        auto k = q.front(); q.pop();
        Node *node = k.first;
        if(mp[k.second] == 0) mp[k.second] = node->data;
        
        if(node->left != NULL)
            q.push(make_pair(node->left, k.second-1));
        if(node->right != NULL)
            q.push(make_pair(node->right, k.second+1));
    }
    
    for(auto k: mp) cout<<k.second<<" ";
    cout<<endl;
}