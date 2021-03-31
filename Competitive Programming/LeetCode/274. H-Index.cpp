// Question: https://leetcode.com/problems/h-index/
// Solution: https://leetcode.com/submissions/detail/474527586/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n-1;
        
        sort(citations.begin(), citations.end());
        
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(n-mid <= citations[mid])
                r = mid - 1;
            else l = mid + 1;
        }
        
        return n - l;
    }
};

int main(){
    return 0;
}