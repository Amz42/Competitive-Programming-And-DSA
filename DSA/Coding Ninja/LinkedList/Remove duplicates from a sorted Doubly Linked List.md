# [Remove duplicates from a sorted Doubly Linked List](https://www.codingninjas.com/studio/problems/unique-sorted-list_2420283)

## Solution:
```c++
Node *removeDuplicates(Node *head) {
    Node* curr = head;

    while(curr != nullptr) {
        Node* ptr = curr->next;
        while(ptr != nullptr && ptr->data == curr->data) {
            ptr = ptr->next;
        }
        curr->next = ptr;
        if(ptr != nullptr)
            ptr->prev = curr;

        curr = curr->next;
    }

    return head;
}

```