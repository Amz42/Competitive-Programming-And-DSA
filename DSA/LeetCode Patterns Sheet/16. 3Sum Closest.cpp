// Question: https://leetcode.com/problems/3sum-closest/
// Solution: https://leetcode.com/submissions/detail/500829996/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        int diff = INT_MAX, sm;
        
        sort(a.begin(), a.end());
        
        int n = a.size();
        for(int i=0;i<n;i++){
            int l = i+1;
            int r = n-1;
            
            while(l<r){
                int sum = a[i] + a[l] + a[r];
                if(abs(target-sum)<diff){
                    diff = abs(target-sum);
                    sm = sum;
                }
                
                if(sum<target) l++;
                else r--;
            }
        }
        
        return sm;
    }
};

int main(){
  return 0;
}