// Question: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=4fdfbd85b70eb3cba793de27bb0a3920&pid=700099&user=amanguptarkg6

// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


 // } Driver Code Ends
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head){
        Node* p = head;
        Node* q = head;
        while(p->next != NULL && p->next->next!=NULL){
            p = p->next->next;
            q = q->next;
            if(p==q) return true;
        }
        
        return false;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}
  // } Driver Code Ends