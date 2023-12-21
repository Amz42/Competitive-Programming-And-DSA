# [Deleting and Adding the last node](https://www.codingninjas.com/studio/problems/deleting-and-adding-the-last-node_1170051)

## Solution:
```c++
Node *delAddLastNode(Node *head){
	if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while(curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    curr->next = head;

    return curr;
}
```