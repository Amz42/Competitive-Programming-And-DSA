// Question: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#
// Solution1: https://practice.geeksforgeeks.org/viewSol.php?subId=36c5efd75d6468b493eeab9f92ff1d30&pid=700523&user=amanguptarkg6
// Solution2: https://practice.geeksforgeeks.org/viewSol.php?subId=944440cb2a7f5a87700692ca9e4a9ab4&pid=700523&user=amanguptarkg6

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////     Solution-1
/////////////////////////////////////////////////////////////////////////////////////////////
class Solution{
    Node* findMid(Node* head){
        if(head == NULL)
            return NULL;
        Node* s = head;
        Node* f = head;
        
        while(f->next!=NULL && f->next->next!=NULL){
            f = f->next->next;
            s = s->next;
        }
        
        f = s->next;
        s->next = NULL;
        return f;
    }
    
    Node* merge(Node* l, Node* r){
        if(l==NULL) return r;
        if(r==NULL) return l;
        
        if(l->data <= r->data){
            l->next = merge(l->next, r);
            return l;
        }else{
            r->next = merge(l, r->next);
            return r;
        }
    }
    
    Node* divide(Node* head){
        if(head==NULL || head->next==NULL)
            return head;
        Node* mid = findMid(head);
        Node* l = divide(head);
        Node* r = divide(mid);
        return merge(l,r);
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        return divide(head);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////     Solution-1
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////     Solution-2
/////////////////////////////////////////////////////////////////////////////////////////////
class Solution{
    Node* merge(Node* l, Node* r){
        Node* head = NULL;
        Node* p = NULL;
        
        while(l!=NULL && r!=NULL){
            int data;
            if(l->data<r->data) data = l->data, l = l->next;
            else data = r->data, r = r->next;
            
            if(head==NULL)
                p = head = new Node(data);
            else 
                p = p->next = new Node(data);
        }
        
        while(l!=NULL){
            p = p->next = new Node(l->data);
            l = l->next;
        }
        
        while(r!=NULL){
            p = p->next = new Node(r->data);
            r = r->next;
        }
        
        return head;
    }
    Node* divide(Node* l){
        if(l==NULL || l->next==NULL) return l;
        Node* f = l;
        Node* s = l;
        
        while(f->next!=NULL && f->next->next!=NULL)
            f = f->next->next, s = s->next;
        f = s;
        s = s->next;
        f->next = NULL;
        
        f = divide(l);
        s = divide(s);
        
        return merge(f,s);
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        return divide(head);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////     Solution-2
/////////////////////////////////////////////////////////////////////////////////////////////

// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends