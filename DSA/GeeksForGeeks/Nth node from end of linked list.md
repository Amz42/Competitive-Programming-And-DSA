### GeeksForGeeks - Nth node from end of linked list

[Question](https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=821dbe0b1728bce65d0ceb88b4c02956&pid=700170&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

int getNthFromLast(Node *head, int n){
    Node *fast = head, *slow = head;
    
    while(n && fast){
        n--;
        fast = fast->next;
    }
    
    if(n) return -1;
    
    while(fast)
        fast = fast->next,
        slow = slow->next;
    
    return slow->data;
}
```