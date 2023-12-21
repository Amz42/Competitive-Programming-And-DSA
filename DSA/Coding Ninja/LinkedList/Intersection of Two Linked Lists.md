# [Intersection of Two Linked Lists](https://www.codingninjas.com/studio/problems/intersection-of-linked-list_630457)

## Solution: using Cycle detection Algo
```c++
Node* findIntersection(Node *firstHead, Node *secondHead) {
    if(firstHead == nullptr || secondHead == nullptr)
        return nullptr;
    Node* ptr = firstHead;
    
    // Creating a cycle in first linkedList
    while(ptr->next != nullptr) ptr = ptr->next;
    ptr->next = firstHead;

    Node* f = secondHead;
    Node* s = secondHead;
    while(f != nullptr && f->next != nullptr) {
        f = f->next->next;
        s = s->next;

        if(f == s) {
            // Cycle exists. that means intersection is present
            f = secondHead;
            while(f != s) {
                f = f->next;
                s = s->next;
            }
            ptr->next = nullptr;
            return f;
        }
    }
    
    ptr->next = nullptr;
    return nullptr;
}
```