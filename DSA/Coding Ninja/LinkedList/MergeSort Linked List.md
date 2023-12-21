# [MergeSort Linked List](https://www.codingninjas.com/studio/problems/mergesort-linked-list_630514)

## Solution: using Merge sort approach
```c++
node* merge(node* l, node* r) {
    if(l == nullptr) return r;
    if(r == nullptr) return l;

    if(l->data < r->data) {
        l->next = merge(l->next, r);
        return l;
    } else {
        r->next = merge(l, r->next);
        return r;
    }
}

node* divide(node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;

    node* prev = head;
    node* slow = head;
    node* fast = head;
    // Dividing linkedList into 2 halfs
    while(fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    
    node* l = divide(head);
    node* r = divide(slow);

    return merge(l, r);
}

node* mergeSort(node *head) {
    return divide(head);
}
```