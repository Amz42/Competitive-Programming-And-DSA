// Question: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=8dde0bbbedd2b09548072cf6f3aedd67&pid=700053&user=amanguptarkg6

//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }
    cout<<"\n";
}

 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

//////////////////////////////////////////////////////////////////////////////////////////
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
    Node* addOne(Node *head) {
        head = reverse(head);
        Node* p = head;
        Node* prev;
        
        p->data += 1;
        int carry = p->data/10;
        p->data %= 10;
        
        prev = p;
        p = p->next;
        
        while(carry){
            if(p == NULL){
                p = new Node(carry%10);
                carry /= 10;
                prev->next = p;
            }else{
                p->data += carry;
                carry = p->data/10;
                p->data %= 10;
            }
            
            prev = p;
            p = p->next;
        }
        
        return reverse(head);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////
// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends