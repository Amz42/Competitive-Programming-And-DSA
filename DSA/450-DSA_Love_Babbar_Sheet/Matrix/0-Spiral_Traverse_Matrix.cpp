// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// https://practice.geeksforgeeks.org/viewSol.php?subId=f7f579444aa4ba674977cd806973e95b&pid=701264&user=amanguptarkg6

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution{
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c){
        vector<int> answer;
        int up=0, down = r-1, left = 0, right = c-1;
        
        while(up <= down && left<=right){
            for(int i=left;i<=right;i++) answer.push_back(matrix[up][i]); up++;
            if(up>down || right<left) break;
            for(int i=up;i<=down;i++) answer.push_back(matrix[i][right]); right--;
            if(up>down || right<left) break;
            for(int i=right;i>=left;i--) answer.push_back(matrix[down][i]); down--;
            if(up>down || right<left) break;
            for(int i=down;i>=up;i--) answer.push_back(matrix[i][left]); left++;
            if(up>down || right<left) break;
        }
        
        return answer;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends