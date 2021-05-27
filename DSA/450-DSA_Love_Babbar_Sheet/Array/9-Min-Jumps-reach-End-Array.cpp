// Question: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=420daac7f23a0cb80e41caddc0744776&pid=701393&user=amanguptarkg6
// Solution-2: https://practice.geeksforgeeks.org/viewSol.php?subId=7ae9f3e22161a7fbc8045ec9be1266b9&pid=701393&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

class Solution2{
  public:
    int minJumps(int arr[], int n){
        int current_reach = 0;
        int max_reach = 0;
        int jumps = 0;
        
        for(int i=0;i<n;i++){
            max_reach = max(max_reach, arr[i]+i);
            if(i>current_reach) return -1;
            if(i == n-1) break;
            if(current_reach == i)
                jumps++,
                current_reach = max_reach;
        }
        
        return jumps;
    }
};

// Function to return minimum number of jumps to end of array
int minJumps(int a[], int n){
    if(n && a[0]==0) return -1;
    
    int jumps = 1;
    int steps = a[0];
    int max_reach = a[0];
    
    for(int i = 1;i<n;i++){
        if(i==n-1) return jumps;
        
        // maximize max reachable point
        max_reach = max(max_reach, i+a[i]);
        
        steps--;
        
        if(steps==0){
            // we must have taken a jump before
            jumps++;
            if(i>=max_reach) return -1;
            
            // number of steps we're able to take now
            steps = max_reach - i;
        }
    }
    
    return -1;
}

int main(){
    int t; cin>>t; while(t--){
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}