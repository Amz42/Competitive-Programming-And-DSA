### GeeksForGeeks - Finding middle element in a linked list

[Question](https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=9e846326dd4497c1b35d2551d5acfdda&pid=700171&user=amanguptarkg6)

#### C++
```c++
class Solution{
public:
    int getMiddle(Node *head){
        Node *slow = head, *fast = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return fast->next ? slow->next->data : slow->data;
    }
};
```