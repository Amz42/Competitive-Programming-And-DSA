# [Program to delete loop in a link list](https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1)

## Solution:
```c++
class Solution{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head){
        Node* f = head;
        Node* s = head;
        Node* prev;
        
        while(f->next!=NULL && f->next->next!=NULL){
            prev = s;
            f = f->next->next;
            s = s->next;
            
            if(f == s){
                f = head;
                while(f!=s){
                    f = f->next;
                    prev = s;
                    s = s->next;
                }
                prev->next = NULL;
            }
        }
        
        return;
    }
};
```