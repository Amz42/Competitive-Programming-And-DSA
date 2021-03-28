// Question: https://practice.geeksforgeeks.org/problems/box-stacking/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=4f7c0a05a699dea064334341e3c567ff&pid=700371&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    
    static bool compare(array<int,3>& a, array<int,3>& b){
        // to sort in descending order
        if(a[1]!=b[1]) return a[1] > b[1];
        return a[2] > b[2];
    }
    
    
    int maxHeight(int height[],int width[],int length[],int n){
        vector<array<int,3>> points(3*n);
        int dp[3*n], answer = 0;
        
        // pointer to add box's to array
        int k = 0;
        
        // Adding all possible rotations of a Box in sorted order
        for(int i=0;i<n;i++){
            points[k++] = {
                height[i],
                max(length[i], width[i]),
                min(length[i], width[i]) 
            };
            
            points[k++] = {
                width[i],
                max(length[i], height[i]),
                min(length[i], height[i])
            };
            
            points[k++] = {
                length[i],
                max(height[i], width[i]),
                min(height[i], width[i])
            };
        }
        
        sort(points.begin(), points.end(), compare);
        
        for(int i=0; i<3*n; i++){
            int max_height_stack = 0;
            for(int j=0;j<i;j++)
                if(
                    (points[j][2] > points[i][2]) && (points[j][1] > points[i][1])
                ) max_height_stack = max(max_height_stack, dp[j]);
            
            // adding current box's height & max height possible from DP
            dp[i] = points[i][0] + max_height_stack;
            
            // maximizing the answer
            answer = max(answer, dp[i]);
        }
        
        return answer;
    }
};

int main(){
	int t; cin>>t; while(t--){
        int n; cin>>n;
        int A[105],B[105],C[105];
        
        for(int i=0;i<n;i++){
            int a,b,c; cin>>a>>b>>c;
            A[i]=a; B[i]=b; C[i]=c;
        }
        
        Solution ob; cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
}