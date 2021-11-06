### GeeksForGeeks - Rotate a Linked List

[Question](https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=9bdf092d25102b3b073f7ec4abcc3a3b&pid=700023&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

Node* rotate(Node* head, int k){
    if(k==0) return head;
    Node *ptr = head, *ptr2;
    
    k--;
    while(k--) ptr = ptr->next;

    if(ptr->next==NULL) return head;
    ptr2 = ptr->next;
    ptr->next = NULL;
    
    ptr = ptr2;
    while(ptr->next!=NULL) ptr = ptr->next;
    ptr->next = head;
    
    return ptr2;
}
```