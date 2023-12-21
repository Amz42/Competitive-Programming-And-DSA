# [Reverse Linked List](https://www.codingninjas.com/studio/problems/reverse-the-singly-linked-list_799897)

## Solution1 (Recursive):
```c++
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    
    LinkedListNode<int>* newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}
```

## Solution2 (Iterative):
```c++
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    LinkedListNode<int> *prev, *curr, *nxt;
    prev = curr = nullptr;
    nxt = head;
    
    while(nxt != nullptr) {
        curr = nxt;
        nxt = nxt->next;
        curr->next = prev;
        prev = curr;
    }

    return curr;
}
```