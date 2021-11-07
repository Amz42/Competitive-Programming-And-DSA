### GeeksForGeeks - Rearrange a linked list

[Question](https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1/#)
| [Solution-1](https://practice.geeksforgeeks.org/viewSol.php?subId=e0388a34d905fa3cf8bf3ce6545efc70&pid=700045&user=amanguptarkg6)
| [Solution-2](https://practice.geeksforgeeks.org/viewSol.php?subId=2c604a8c6074978fbef22aab1975eec4&pid=700045&user=amanguptarkg6)

#### C++

##### Solution-1
```c++
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution{
public:
    void rearrangeEvenOdd(Node *head){
        Node* oddHead = new Node(-1);
        Node* odd = oddHead;
        Node* evenHead = new Node(-1);
        Node* even = evenHead;
        
        
        bool turn = true;
        Node* curr = head;
        while(curr){
            Node* nxt = curr->next;
            
            if(turn) {
                odd->next = curr;
                odd = odd->next;
                odd->next = NULL;
            } else {
                even->next = curr;
                even = even->next;
                even->next = NULL;
            }
            
            turn = !turn;
            curr = nxt;
        }
        
        odd->next = evenHead->next;
        head = oddHead->next;
    }
};
```

##### Solution-2
```c++
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution{
public:
    void rearrangeEvenOdd(Node *head){
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;
        
        while(odd->next && even->next){
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        
        odd->next = evenHead;
        if(even) even->next = NULL;
    }
};
```