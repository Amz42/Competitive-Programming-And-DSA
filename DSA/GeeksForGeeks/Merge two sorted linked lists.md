### GeeksForGeeks - Merge two sorted linked lists

[Question](https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1/#)
| [Solution-1 (Recursive)](https://practice.geeksforgeeks.org/viewSol.php?subId=57d67d770753a25db4210eabba29ebc6&pid=700176&user=amanguptarkg6)
| [Solution-2 (Iterative)](https://practice.geeksforgeeks.org/viewSol.php?subId=c95e17e7c5574a01ff6b0b20c23c8ca6&pid=700176&user=amanguptarkg6)

#### C++

##### Solution-1 (Recursive)
```c++
// Time Complexity: O(n+m)
// Space Complexity: O(n+m)

Node* sortedMerge(Node* h1, Node* h2){
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    
    if(h1->data < h2->data) {
        h1->next = sortedMerge(h1->next, h2);
        return h1;
    }
    
    h2->next = sortedMerge(h1, h2->next);
    return h2;
};
```

##### Solution-2 (Iterative)
```c++
// Time Complexity: O(n+m)
// Space Complexity: O(1)

Node* sortedMerge(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node *p = dummy, *h1 = head1, *h2 = head2;
    
    while(h1 && h2){
        if(h1->data < h2->data){
            p->next = h1;
            h1 = h1->next;
        } else {
            p->next = h2;
            h2 = h2->next;
        }
        p = p->next;
    }
    
    while(h1)
        p = p->next = h1,
        h1 = h1->next;
    
    while(h2)
        p = p->next = h2,
        h2 = h2->next;
    
    return dummy->next;
}
```