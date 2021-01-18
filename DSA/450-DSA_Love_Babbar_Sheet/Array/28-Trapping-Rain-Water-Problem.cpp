// Question: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=226c5c2a5993293ffbd0b524815ea8a4&pid=701211&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;

/*
APPROACH:
    take 2 pointers left & right, & 2 variables to store left & right max height bar
    if maxLeft > rightMax:
        then right side pillar's volume will be subtracted from maxRight bar
    else:
        then left side pillar's volume will be subtracted from maxLeft bar
*/

int trappingWater(int a[], int n){
    int left = 0, right = n-1;
    int maxLeft = 0, maxRight = 0;
    int answer = 0;
    
    while(left<right){
        maxLeft = max(maxLeft, a[left]);
        maxRight = max(maxRight, a[right]);
        if(maxLeft>maxRight){
            answer += (maxRight - a[right]);
            right--;
        }else{
            answer += (maxLeft - a[left]);
            left++;
        }
    }    
    return answer;
}

int main(){
    int t; cin >> t; while(t--){
        int n; cin >> n;
        int a[n];
        for(int i =0;i<n;i++) cin >> a[i];
        cout << trappingWater(a, n) << endl;   
    }   
    return 0;
}