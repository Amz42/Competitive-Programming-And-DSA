// Question: https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=baf5fa0b1f62da7cf634ef1d2f53af36&pid=700311&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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

bool isHeap(struct Node * tree);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isHeap(root)<< endl;
  }
  return 0;
}

// } Driver Code Ends


/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/*You are required to complete this method */
bool isHeap(Node * tree){
    bool isLeftOk = true;
    bool isRightOk = true;
    
    if(tree->left != NULL){
        isLeftOk = ( (tree->data) < (tree->left->data)
                ? false 
                : isHeap(tree->left)
        );
    }
    
    if(tree->right != NULL){
        isRightOk = ( (tree->data) < (tree->right->data)
                ? false 
                : isHeap(tree->right)
        );
    }
    
    
    return (isLeftOk && isRightOk);
}