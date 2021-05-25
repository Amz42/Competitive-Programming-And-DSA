// Question: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Solution: https://leetcode.com/submissions/detail/497929550/

#include<bits/stdc++.h>
using namespace std;

/***Definition for singly-linked list.*/
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
        ListNode* p = head;
        ListNode* s = p->next;
        
        while(s != nullptr){
            while(s != nullptr && s->val == p->val)
                s = s->next;
            p = p->next = s;
            if(s != nullptr)
                s = s->next;
        }
        
        return head;
    }
};

int main(){
  return 0;
}