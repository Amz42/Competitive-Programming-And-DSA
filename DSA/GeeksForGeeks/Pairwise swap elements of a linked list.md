### GeeksForGeeks - Pairwise swap elements of a linked list

[Question](https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=f9d77b6239f0be2037bc081060e16c8b&pid=700024&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution{
public:
    Node* pairWiseSwap(struct Node* head) {
        if(head->next == NULL) return head;
        Node* prev = new Node(-1);
        prev->next = head;
        
        Node* newHead = NULL;
        
        while(prev && prev->next && prev->next->next) {
            Node* c1 = prev->next;
            Node* c2 = prev->next->next;
            
            c1->next = c2->next;
            c2->next = c1;
            prev->next = c2;
            
            if(newHead == NULL)
                newHead = prev->next;
            
            prev = prev->next->next;
        }
        
        return newHead;
    }
};
```