// Question: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f4e222257ec775958c8d8b0eec5bcd69&pid=700043&user=amanguptarkg6

// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
class Solution{
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* nxt;
        
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* f, struct Node* s){
        f = reverse(f);
        s = reverse(s);
        
        int carry = ((f->data)+(s->data))/10;
        
        Node* l = new Node(((f->data)+(s->data))%10);
        
        f = f->next;
        s = s->next;
        
        Node* p = l;
        while(f!=NULL || s!=NULL){
            int data = carry;
            if(f!=NULL) data += (f->data), f = f->next;
            if(s!=NULL) data += (s->data), s = s->next;
            carry = data/10;
            p->next = new Node(data%10);
            p = p->next;
        }
        
        while(carry){
            p->next = new Node(carry%10);
            carry /= 10;
            p = p->next;
        }
        
        return reverse(l);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends