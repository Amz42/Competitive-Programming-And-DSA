// Question: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Solution: https://leetcode.com/submissions/detail/500003092/

#include<bits/stdc++.h>
using namespace std;

class CustomStack {
    int capacity, size;
    stack<int> s;
    vector<int> inc;
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
        size = 0;
        inc.resize(capacity+10, 0);
    }
    
    void push(int x) {
        if(size == capacity) return;
        s.push(x);
        size++;
    }
    
    int pop() {
        if(size == 0) return -1;
        
        int top = s.top(); s.pop();
        top += inc[size];
        inc[size-1] += inc[size];
        inc[size] = 0;
        size--;
        
        return top;
    }
    
    void increment(int k, int val) {
        inc[min(k, size)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main(){
  return 0;
}