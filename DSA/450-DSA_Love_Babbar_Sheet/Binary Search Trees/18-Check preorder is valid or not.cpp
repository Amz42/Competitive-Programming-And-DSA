// Question: https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=320f4da321e76368d4e447677eb2c4bb&pid=701734&user=amanguptarkg6

//Initial template for C++

/* A O(n) iterative program for construction of BST from preorder traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A Stack has array of Nodes, capacity, and top
typedef struct Stack
{
    int top;
    int capacity;
    Node* *array;
} Stack;

// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to create a stack of given capacity
Stack* createStack( int capacity )
{
    Stack* stack = (Stack *)malloc( sizeof( Stack ) );
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (Node **)malloc( stack->capacity * sizeof( Node* ) );
    return stack;
}

// A utility function to check if stack is full
int isFull( Stack* stack )
{
    return stack->top == stack->capacity - 1;
}

// A utility function to check if stack is empty
int isEmpty( Stack* stack )
{
    return stack->top == -1;
}

// A utility function to push an item to stack
void push( Stack* stack, Node* item )
{
    if( isFull( stack ) )
        return;
    stack->array[ ++stack->top ] = item;
}

// A utility function to remove an item from stack
Node* pop( Stack* stack )
{
    if( isEmpty( stack ) )
        return NULL;
    return stack->array[ stack->top-- ];
}

// A utility function to get top node of stack
Node* peek( Stack* stack )
{
    return stack->array[ stack->top ];
}

bool canRepresentBST(int pre[], int n)
{
    // Create an empty stack
    stack<int> s;

    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;

    // Traverse given array
    for (int i=0; i<n; i++)
    {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (pre[i] < root)
            return false;

        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top()<pre[i])
        {
            root = s.top();
            s.pop();
        }

        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(pre[i]);
    }
    return true;
}


// A utility function to print postorder traversal of a Binary Tree
void printPostorder (Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

// The main function that constructs BST from pre[]
Node* constructTree (int *, int );

int main()
{
    // Note that size of arr[] is considered 100 according to
    // the constraints mentioned in problem statement.
    int arr[1000], x, t, n;

    // Input the number of test cases you want to run
    cin >> t;

    // One by one run for all input test cases
    while (t--)
    {
        // Input the size of the array
        cin >> n;

        // Input the array
        for (int i=0; i<n; i++)
            cin >> arr[i];

        printPostorder(constructTree(arr, n));
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//User function template in C++
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
// pre : given preorder if the tree
// size : size of the array
// print postorder traveresal of the tree

void makeBST(Node* root, int pre[], int& pos, int& size, int L, int R){
    // LEFT SUBTREE
    if(pos>=size || pre[pos] < L || pre[pos] > R) return;
    if(pre[pos] < root->data){
        root->left = newNode(pre[pos++]);
        makeBST(root->left, pre, pos, size, L, root->data);
    }
    
    // RIGHT SUBTREE
    if(pos>=size || pre[pos] < L || pre[pos] > R) return;
    if(pre[pos] > root->data){
        root->right = newNode(pre[pos++]);
        makeBST(root->right, pre, pos, size, root->data, R);
    }
}

Node* constructTree(int pre[], int size) {
    int pos = 0;
    if(size == 0) return NULL;
    Node* root = newNode(pre[pos++]);
    if(size == 1) return root;
    makeBST(root, pre, pos, size, INT_MIN, INT_MAX);
    return root;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////