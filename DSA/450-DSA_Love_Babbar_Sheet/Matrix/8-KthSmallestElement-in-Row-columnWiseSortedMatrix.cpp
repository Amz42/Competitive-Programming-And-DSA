// Question: https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=00e3f710812b2677c88af0bbfcb2d851&pid=700309&user=amanguptarkg6

// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>mat[i][j];
        int r; cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
    return 0;
}

int kthSmallest(int mat[MAX][MAX], int n, int k){
    priority_queue<int> pq;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(pq.size()<k) pq.push(mat[i][j]);
            else if(mat[i][j]<pq.top()){
                pq.pop();
                pq.push(mat[i][j]);
            }
        }
    }
    return pq.top();
}