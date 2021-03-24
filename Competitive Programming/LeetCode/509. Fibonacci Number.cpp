// Question: https://leetcode.com/problems/fibonacci-number/
// Solution: https://leetcode.com/submissions/detail/471931305/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        
        int x = 0, y = 1, z;
        for(int i=0;i<n-1;i++){
            z = x + y;
            x = y;
            y = z;
        }
        
        return z;
    }
};

int main(){
    // 0 1 1 2 3 5 8 13 ...........
    Solution s = *new Solution();
    cout<<s.fib(5);
    return 0;
}