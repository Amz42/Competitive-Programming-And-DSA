// Article: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

#include <bits/stdc++.h>
using namespace std;

int n,sum;
bool dp[101][101];
void printSubset(int i, int j, int a[], vector<int>& subset){
    if(i==0 || j==0){
        for(int k: subset) cout << k << " "; cout<<endl;
        return;
    }
    if(a[i-1]<=j && dp[i-1][j-a[i-1]]){
        subset.push_back(a[i-1]);
        printSubset(i-1, j-a[i-1], a, subset);
        subset.pop_back();
    }
    if(dp[i-1][j]) printSubset(i-1, j, a, subset);
}

int main(){
    cout<<"Enter no. of elements: "; cin>>n;
    cout<<"Enter elements: ";
    int a[n]; for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Enter Desired sum: "; cin>>sum;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                dp[i][j] = true;
                continue;
            }
            if(i==0){
                dp[i][j] = false;
                continue;
            }
            
            if(a[i-1]>sum){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
    }
    
    bool found = dp[n][sum];
    cout<<( found ? "Subset Found:\n" : "Subset Not Found...");
    
    if(found){
        vector<int> subset;
        printSubset(n, sum, a, subset);
    }
    
    return 0;
}