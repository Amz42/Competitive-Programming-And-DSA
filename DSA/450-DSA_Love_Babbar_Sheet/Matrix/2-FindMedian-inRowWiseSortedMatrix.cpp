// Question: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=8438d50c2e48b7305a2be0019da05b17&pid=704712&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0;i<r;i++){
            mn = min(mn, matrix[i][0]);
            mx = max(mx, matrix[i][c-1]);
        }
        
        int HalfOfElements = (r*c+1)/2;
        
        while(mn<mx){
            int mid = mn + ( mx - mn ) / 2;
            int smallerElements = 0;
            
            for(int i=0;i<r;i++)
            smallerElements += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            
            if(smallerElements < HalfOfElements) mn = mid + 1;
            else mx = mid;
        }
        
        return mn;
    }
};

int main(){
    int t; cin>>t; while(t--){
        int r, c; cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i) for(int j = 0;j < c; ++j) cin>>matrix[i][j];
        Solution obj; cout<<obj.median(matrix, r, c)<<endl;
    }
    return 0;
}