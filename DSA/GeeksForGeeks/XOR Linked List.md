### GeeksForGeeks - XOR Linked List

[Question](https://practice.geeksforgeeks.org/problems/xor-linked-list/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=60ce8bdf40211cf5b6ec8aaae3ec1a25&pid=700562&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

struct Node *insert(struct Node *head, int data) {
    struct Node* newNode = new Node(data);
    newNode->npx = XOR(NULL, head);
    
    if(head){
        struct Node* next = XOR(NULL, head->npx);
        head->npx = XOR(newNode, next);
    }
    
    head = newNode;
}

vector<int> printList(struct Node *head) {
    vector<int> answer;
    struct Node *curr = head, *prev = NULL;
    
    while(curr){
        answer.push_back(curr->data);
        struct Node* next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    
    return answer;
}
```