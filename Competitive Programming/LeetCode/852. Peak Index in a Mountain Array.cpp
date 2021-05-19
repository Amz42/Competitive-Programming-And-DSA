// Question: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Solution: https://leetcode.com/submissions/detail/495037451/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int l = 0;
        int h = a.size()-1;
        
        while(l<h){
            int mid = l + (h - l) / 2;
            if(a[mid]<a[mid+1])
                l = mid + 1;
            else
                h = mid;
        }
        
        return l;
    }
};

int main(){
  return 0;
}