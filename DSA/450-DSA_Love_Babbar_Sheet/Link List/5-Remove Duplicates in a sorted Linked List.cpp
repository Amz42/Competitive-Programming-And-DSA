// Question: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b65487b6aa921e6c9867e6f07b671569&pid=700196&user=amanguptarkg6

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

void removeDuplicates(struct Node* head){
    struct Node* p = head;
    
    while(p!=NULL){
        struct Node* s = p->next;
        while(s!=NULL && s->data == p->data){
            struct Node* prev = s;
            s = s->next;
            free(prev);
        }
        p->next = s;
        p = p->next;
    }
    
    return;
}

// { Driver Code Starts.

    
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      insert();
      removeDuplicates(start);
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