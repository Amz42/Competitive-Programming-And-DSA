// Question: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=cb631e87b02b6d77d50b41d103f00cf1&pid=700191&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

Node* inputList(int size){
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size){
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n){
    while(n){
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node{
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

*/
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
Node* findIntersection(Node* f, Node* s){
    Node* l = NULL;
    Node* p = NULL;
    
    while(f!=NULL && s!=NULL){
        if(f->data<s->data) f = f->next;
        else if(f->data>s->data) s = s->next;
        else{
            if(l==NULL){
                l = new Node(f->data);
                p = l;
            }else p = p->next = new Node(f->data);
            f = f->next;
            s = s->next;
        }
    }
    
    return l;
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////