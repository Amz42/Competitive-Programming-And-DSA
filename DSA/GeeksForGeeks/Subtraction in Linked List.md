### GeeksForGeeks - Subtraction in Linked List

[Question](https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=cda3522e02896b4d237ef003e962a31d&pid=700313&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(n) (for resultant list)

Node* reverse(Node* head){
    Node *prev = NULL, *curr = NULL, *next = head;
    
    while(next){
        curr = next;
        next = next->next;
        curr->next = prev;
        prev = curr;
    }
    
    return curr;
}

pair<Node*, Node*> bigSmall(Node* list1, Node* list2){
    Node *l1 = list1, *l2 = list2;
    int n1 = 0, n2 = 0;
    bool big1st = false;
    
    while(l1 || l2){
        if(l1 && l2)
            big1st = l1->data >= l2->data;
        
        if(l1) n1++, l1 = l1->next;
        if(l2) n2++, l2 = l2->next;
    }
    
    if(n1 != n2)
        return n1 > n2 ? make_pair(list1, list2) : make_pair(list2, list1);
    
    return big1st
        ? make_pair(list1, list2)
        : make_pair(list2, list1);
}

Node* removeLeading0(Node* head){
    while(head && head->data == 0)
        head = head->next;
    return head;
}

Node* subLinkedList(Node* list1, Node* list2){
    list1 = removeLeading0(list1);
    list2 = removeLeading0(list2);
    pair<Node*, Node*> k = bigSmall(reverse(list1), reverse(list2));
    Node *l1 = k.first, *l2 = k.second;
    
    Node* newHead = new Node(-1);
    Node* prev = newHead;
    bool borrow = false;
    
    while(l1){
        int data = l1->data - (borrow ? 1 : 0) - (l2 ? l2->data : 0);
        borrow = data < 0 ? true : false;
        if(data < 0) data += 10;
        
        prev->next = new Node(data);
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
        prev = prev->next;
    }
    
    newHead = removeLeading0(reverse(newHead->next));
    return newHead ? newHead : new Node(0);
}
```