### GeeksForGeeks - Reverse a linked list

[Question](https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1/)
| [Solution-1 (Iterative)](https://practice.geeksforgeeks.org/viewSol.php?subId=7fd2f0b06278de04fba8f385db8ad989&pid=700005&user=amanguptarkg6)
| [Solution-2 (Recursive)](https://practice.geeksforgeeks.org/viewSol.php?subId=064b060bf03d452bbce254e13c800f16&pid=700005&user=amanguptarkg6)

#### C++

##### Solution-1 (Iterative)
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution{
public:
    struct Node* reverseList(struct Node *head){
        struct Node* prev = NULL, *curr = NULL, *next = head;
        
        while(next) {
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
        }
        
        return curr;
    }
};
```

##### Solution-2 (Recursive)
```c++
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution{
public:
    struct Node* reverseList(struct Node *head){
        if(head == NULL || head->next == NULL) return head;
        
        Node* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
};
```