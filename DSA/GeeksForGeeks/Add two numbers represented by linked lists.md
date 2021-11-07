### GeeksForGeeks - Add two numbers represented by linked lists

[Question](https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=f4e222257ec775958c8d8b0eec5bcd69&pid=700043&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n+m)
// Space Complexity: O(max(n,m)) (for resultant list)

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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* f, struct Node* s){
        f = reverse(f);
        s = reverse(s);
        
        int carry = ((f->data)+(s->data))/10;
        
        Node* l = new Node(((f->data)+(s->data))%10);
        
        f = f->next;
        s = s->next;
        
        Node* p = l;
        while(f!=NULL || s!=NULL){
            int data = carry;
            if(f!=NULL) data += (f->data), f = f->next;
            if(s!=NULL) data += (s->data), s = s->next;
            carry = data/10;
            p->next = new Node(data%10);
            p = p->next;
        }
        
        while(carry){
            p->next = new Node(carry%10);
            carry /= 10;
            p = p->next;
        }
        
        return reverse(l);
    }
};
```