// Question: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=226c5c2a5993293ffbd0b524815ea8a4&pid=701211&user=amanguptarkg6

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
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


// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends