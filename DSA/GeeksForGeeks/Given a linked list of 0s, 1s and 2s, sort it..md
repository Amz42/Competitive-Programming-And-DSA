### GeeksForGeeks - Given a linked list of 0s, 1s and 2s, sort it.

[Question](https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=bd7ba955be11b49cd73a5a9f9fc0d2e1&pid=700028&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution{
public:
    Node* segregate(Node *head) {
        Node* prev = head, *curr = head;
        
        while(curr){
            if(curr->data == 0)
                swap(prev->data, curr->data),
                prev = prev->next;
            curr = curr->next;
        }
        
        curr = prev;
        while(curr){
            if(curr->data == 1)
                swap(prev->data, curr->data),
                prev = prev->next;
            curr = curr->next;
        }
        
        return head;
    }
};
```