// Question: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=1ef0a6b2131b2257f8825db722557e66&pid=700265&user=amanguptarkg6

// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int K);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
struct compare{
    bool operator()(Node* a, Node* b){
        return (a->data) > (b->data);
    }
};
  
Node* mergeKLists(Node *arr[], int K){
    Node* head = NULL;
    Node* temp;
    // Min-Heap
    priority_queue<Node*, vector<Node*>, compare> q;
    
    for(int i=0;i<K;i++) if(arr[i]!=NULL) q.push(arr[i]);
    
    while(!q.empty()){
        Node* g = q.top(); q.pop();
        
        if(g->next != NULL) q.push(g->next);
        g->next = NULL;
        
        if(head == NULL){ // First Time
            head = g;
            temp = g;
        }else{
            temp->next = g;
            temp = g;
        }
    }
    
    return head;
}