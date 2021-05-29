// Question: https://leetcode.com/problems/min-stack/
// Solution: https://leetcode.com/submissions/detail/499974112/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> original, mini;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int val) {
        if(mini.empty() || val<=mini.top())
            mini.push(val);
        original.push(val);
    }
    
    void pop() {
        if(original.top()==mini.top())
            mini.pop();
        original.pop();
    }
    
    int top() {
        return original.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
  return 0;
}