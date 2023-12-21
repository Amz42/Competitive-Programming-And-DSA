# [Remove Duplicates From an Unsorted Linked List](https://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331)

## Solution:
```c++
Node *removeDuplicates(Node *head) {
    Node* newHead = new Node(0);
    newHead->next = head;

    unordered_set<int> st;
    Node* curr = head;
    while(curr != nullptr) {
        st.insert(curr->data);
        if(curr->next != nullptr && st.find(curr->next->data) != st.end()) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}
```