// Question: https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=5d9f167fd44d9a7145c65e94e34e847b&pid=700678&user=amanguptarkg6

// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
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

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function

bool search(Node* root, int x){
    if(!root) return false;
    if(root->data == x) return true;
    else if(x < root->data) return search(root->left, x);
    else return search(root->right, x);
}

int countPairs(Node* root1, Node* root2, int x){
    if(!root1) return 0;
    return (
        (int)search(root2, x - root1->data) +
        countPairs(root1->left, root2, x) +
        countPairs(root1->right, root2, x)
    );
}