// https://leetcode.com/problems/search-a-2d-matrix/
// Solution 1 => https://leetcode.com/submissions/detail/429892109/
// Solution 2 => https://leetcode.com/submissions/detail/429908289/

#include <bits/stdc++.h>
using namespace std;

// Solution 1
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




// Solution 2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n;

        // finding the row
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (
                // element found at first position
                (matrix[mid][0] == target) ||
                // element may be in last row
                (mid == n - 1 && matrix[mid][0] <= target) ||
                // element is in mid row
                (matrix[mid][0] <= target && mid + 1 < n && matrix[mid + 1][0] > target)
            ) { l = mid; break; }
            else if ( matrix[mid][0] < target ) l = mid + 1;
            else r = mid;
        }

        // finding the column
        int row = l;
        l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return false;
    }
};


int main(){
    //
}