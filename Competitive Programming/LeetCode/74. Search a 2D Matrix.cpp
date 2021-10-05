// Question: https://leetcode.com/problems/search-a-2d-matrix/
// Solution: https://leetcode.com/submissions/detail/429892109/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0, r = n*m-1;
        
        while(l<=r){
            int mid = l + (r-l) / 2;
            if(matrix[mid/m][mid%m]==target) return true;
            else if(matrix[mid/m][mid%m]<target) l = mid + 1;
            else r = mid - 1;
        }
        
        return false;
    }
};

int main(){
  return 0;
}