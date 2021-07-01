// Question: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Solution: https://leetcode.com/submissions/detail/501902108/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char n) {
        int l = 0, r = a.size() - 1;
        
        if(a[r] <= n)
            return a[0];
        
        while(l < r){
            int mid = l + (r - l) / 2;
            if(a[mid]<=n) l = mid + 1;
            else r = mid;
        }
        
        return a[l];
    }
};

int main(){
  return 0;
}