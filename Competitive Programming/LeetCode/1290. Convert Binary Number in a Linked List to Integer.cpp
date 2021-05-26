// Question: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Solution: https://leetcode.com/submissions/detail/498398577/

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**/
class Solution {
    int trav(ListNode* head, int& prod){
        if(head == NULL)
            return 0;
        if(head->next == NULL)
            return (head->val * 1);
        
        int ans = trav(head->next, prod);
        prod *= 2;
        return (head->val * prod + ans);
    }
public:
    int getDecimalValue(ListNode* head) {
        int prod = 1;
        return trav(head, prod);
    }
};

int main(){
  return 0;
}