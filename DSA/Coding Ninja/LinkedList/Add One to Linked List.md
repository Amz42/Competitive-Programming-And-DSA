# [Add One to Linked List](https://www.codingninjas.com/studio/problems/add-one-to-linked-list_920456)

## Solution: using recursion
```c++
int recursive(LinkedListNode<int> *node){
    if(node->data == -1) return 1;

    int carry = recursive(node->next);
    int val = node->data + carry;
    node->data = val % 10;
    return val / 10;
}

LinkedListNode<int>* addOneToList(LinkedListNode<int> *head) {
    int carry = recursive(head);
    LinkedListNode<int>* newHead = head;
    if(carry != 0) {
        LinkedListNode<int>* newNode = new LinkedListNode<int>(carry);
        newNode->next = head;
        newHead = newNode;
    }

    return newHead;
}
```