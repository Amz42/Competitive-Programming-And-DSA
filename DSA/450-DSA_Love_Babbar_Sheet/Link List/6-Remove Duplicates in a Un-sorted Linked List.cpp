// Question: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b691d42ea930c0f4a576629c4309e0cd&pid=700125&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


 // } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node* head){
        Node* prev;
        Node* f = head;
        
        bool a[(int)(1e4+1)] = {0};
        while(f!=NULL){
            if(a[f->data]){
                prev->next = f->next;
                free(f);
                f = prev->next;
            }else{
                a[f->data] = true;
                prev = f;
                f = f->next;
            }
        }
        
        return head;
    }
};


// { Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}  // } Driver Code Ends