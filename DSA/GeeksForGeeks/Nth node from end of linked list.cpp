// Question: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=36493799c0cd81499723423d90684789&pid=700170&user=amanguptarkg6

#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();


 // } Driver Code Ends
//User function Template for C
///////////////////////////////////////////////////////////////////////////////////////////////
//Function to find the data of nth node from the end of a linked list.
int answer, N;
void trav(struct Node* node){
    if(node == NULL) return;
    trav(node->next);
    
    if(--N == 0)
        answer = node->data;
}

int getNthFromLast(struct Node *head, int n){
    N = n;
    answer = -1;
    trav(head);
    return answer;
}
///////////////////////////////////////////////////////////////////////////////////////////////
// { Driver Code Starts.



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      int n,k;
      scanf("%d",&n);
      scanf("%d",&k);
      insert(n);
      int res = getNthFromLast(start,k);
      printf("%d\n",res);
    }
    return 0;

}


 void insert(int n)
 {   int value,i;
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
 




  // } Driver Code Ends