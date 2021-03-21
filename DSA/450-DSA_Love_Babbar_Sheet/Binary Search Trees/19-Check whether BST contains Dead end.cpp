// Question: https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=9350825fd1c80518352fed2377ec4f98&pid=700425&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
void traverse(Node* root, bool& DeadEndFound, int l, int r){
    if(!root || DeadEndFound) return;
    if(l==r || r==1) DeadEndFound = true;
    
    traverse(root->left, DeadEndFound, l, root->data-1);
    traverse(root->right, DeadEndFound, root->data+1, r);
}

/*You are required to complete below method */
bool isDeadEnd(Node *root){
    bool DeadEndFound = false;
    traverse(root, DeadEndFound, INT_MIN, INT_MAX);
    return DeadEndFound;
}

// APPROACH:
// keep recursively traversing through nodes & update range of keys available
// if range shortens down to single element => dead end found
// if max/min of a range is reached to max capacity
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////