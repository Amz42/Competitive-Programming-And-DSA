### GeeksForGeeks - Add 1 to a number represented as linked list

[Question](https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=8dde0bbbedd2b09548072cf6f3aedd67&pid=700053&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution{
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* nxt;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    public:
    Node* addOne(Node *head) {
        head = reverse(head);
        Node* p = head;

        Node* prev;
        
        p->data += 1;
        int carry = p->data/10;
        p->data %= 10;
        
        prev = p;
        p = p->next;
        
        while(carry){
            if(p == NULL){
                p = new Node(carry%10);
                carry /= 10;
                prev->next = p;
            }else{
                p->data += carry;
                carry = p->data/10;
                p->data %= 10;
            }
            
            prev = p;
            p = p->next;
        }
        
        return reverse(head);
    }
};
```
