### GeeksForGeeks - Delete Middle of Linked List

[Question](https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=7418989e09321cf257c6a6f24eec21e1&pid=700175&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

Node* deleteMid(Node* head){
    if(head == NULL) return NULL;
    Node *slow = head, *fast = head->next;
        
    while(fast && fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    
    return head;
}
```