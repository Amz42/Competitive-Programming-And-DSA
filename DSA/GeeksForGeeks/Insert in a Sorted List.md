### GeeksForGeeks - Insert in a Sorted List

[Question](https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=36095114162ae7cb60e1eab19d93c0a6&pid=700540&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution{
public:
    Node *sortedInsert(struct Node* head, int data) {
        Node* dummy = new Node(-1);
        dummy->next = head;
        Node* n = dummy;
        
        while(n->next && n->next->data < data)
            n = n->next;
        
        Node* newNode = new Node(data);
        newNode->next = n->next;
        n->next = newNode;
        
        return dummy->next;
    }
};
```