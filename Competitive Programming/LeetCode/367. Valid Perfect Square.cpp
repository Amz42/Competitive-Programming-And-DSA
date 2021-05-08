// Question: https://leetcode.com/problems/valid-perfect-square/
// Solution: https://leetcode.com/submissions/detail/490275653/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while(l<=r){
            long long int m = l + (r - l) / 2;
            if(m*m == num)
                return true;
            if(m*m < num)
                l = m+1;
            else
                r = m-1;
        }
        return false;
    }
};

int main(){
    return 0;
}