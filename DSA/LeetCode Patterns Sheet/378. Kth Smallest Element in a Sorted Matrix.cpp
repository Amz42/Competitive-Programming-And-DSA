// Question: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Solution: https://leetcode.com/submissions/detail/501925620/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int l = mat[0][0], r = mat[n-1][n-1];
        
        while(l<=r){
            int mid = l + (r - l) / 2;
            int count  = 0;
            
            for(int i=0; i<n; i++){
                int low = 0, high = mat[i].size();
                while(low < high){
                    int midi = low + (high - low) / 2;
                    if(mat[i][midi] <= mid) low = midi + 1;
                    else high = midi;
                }

                count += low;
            }
            
            if(count < k) l = mid + 1;
            else r = mid - 1;
        }
        
        return l;
    }
};

int main(){
  return 0;
}