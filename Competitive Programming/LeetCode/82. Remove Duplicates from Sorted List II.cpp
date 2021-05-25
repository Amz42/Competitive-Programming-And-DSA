// Question: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Solution: https://leetcode.com/submissions/detail/497927013/

#include <bits/stdc++.h>
using namespace std;

/*** Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = new ListNode(-1);
        ListNode* p = newHead; p->next = head;
        ListNode* c = head->next;
        
        while(c != nullptr){
            bool repeated = false;
            while(c != nullptr && c->val == p->next->val){
                repeated = true;
                c = c->next;
            }
            
            if(repeated)
                p->next = c;
            else
                p = p->next;
            
            if(c != nullptr)
                c = c->next;
        }
        
        head = newHead->next;
        // free(newHead);
        return head;
    }
};

int main(){
    return 0;
}