// Question: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=89323601c149d823f0164e5c14e49c84&pid=700163&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* f, Node* s){
    Node* p = f;
    while(p->next!=NULL) p = p->next;
    p->next = f;
    
    Node* fast = s;
    Node* slow = s;
    
    do{
        fast = fast->next->next;
        slow = slow->next;
    } while(fast!=slow);
    fast = s;
    while(fast!=slow) fast = fast->next, slow = slow->next;
    
    p->next = NULL;
    
    return (fast->data);
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////