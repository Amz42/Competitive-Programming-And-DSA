// Question: https://practice.geeksforgeeks.org/problems/find-length-of-loop/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f560a8d85955d05940e6715735ee3590&pid=700620&user=amanguptarkg6

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

int countNodesinLoop(Node* head);

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
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}
// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head){
    struct Node* f = head;
    struct Node* s = head;
    
    while(f->next!=NULL && f->next->next!=NULL){
        f = f->next->next;
        s = s->next;
        if(f==s){
            int count = 0;
            do{
                count++;
                f = f->next;
            }while(f!=s);
            return count;
        }
    }
    
    return 0;
}