// Question: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1#
// (Iterative) Solution-1: https://practice.geeksforgeeks.org/viewSol.php?subId=23198d4a3797809c74cd5698ed654656&pid=700005&user=amanguptarkg6
// (Recursive) Solution-2: https://practice.geeksforgeeks.org/viewSol.php?subId=4aa9ec0c939f64a1ce889a1143b72f80&pid=700005&user=amanguptarkg6

//Initial Template for C
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();
void display(struct Node *head);

 // } Driver Code Ends
//User function Template for C
//////////////////////////////////////////////////////////////////////////////////////////
///////////////           Solution - 1 | (Iterative)
//////////////////////////////////////////////////////////////////////////////////////////
struct Node* reverseList(struct Node *head){
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* nxt = NULL;
    
    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    return prev;
}
//////////////////////////////////////////////////////////////////////////////////////////
///////////////           Solution - 1 | (Iterative)
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
///////////////           Solution - 2 | (Recursive)
//////////////////////////////////////////////////////////////////////////////////////////
struct Node* reverseList(struct Node *head){
    // we reached last node
    if(head == NULL || head->next == NULL)
        return head;
    
    struct Node* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
//////////////////////////////////////////////////////////////////////////////////////////
///////////////           Solution - 2 | (Recursive)
//////////////////////////////////////////////////////////////////////////////////////////

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      insert();
      start = reverseList(start);
      display(start);
      printf("\n");
    }
    return 0;

}


 void insert()
 {
     int n,value,i;
     scanf("%d",&n);
     struct Node *temp;
     for(i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }
 
 void display(struct Node *head)
{
   while(head!=NULL)
  {
   printf("%d ",head->data);
    head=head->next;
  }
}




  // } Driver Code Ends