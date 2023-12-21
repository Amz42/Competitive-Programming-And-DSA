# [Linked List Cycle II](https://www.codingninjas.com/studio/problems/detect-the-first-node-of-the-loop_1112628)

## Solution:
```c++
Node *firstNode(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) {
            fast = head;
            while(fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    
    return nullptr;
}
```