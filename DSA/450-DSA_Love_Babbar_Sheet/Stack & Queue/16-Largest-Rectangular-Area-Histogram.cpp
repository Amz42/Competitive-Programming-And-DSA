// Question: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=624544a8ab718d1397f391d1a0375923&pid=701340&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long long getMaxArea(long long arr[], int n){
    stack<int> st;
    int left[n];
    
    long long int answer = 0;
    
    // finding first smaller bar on left side
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] >= arr[i] ) st.pop();
        left[i] = st.empty() ? i : i-st.top()-1;
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    // finding first smaller bar on right side & calculating area alongside
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i] ) st.pop();
        long long int area = (
            left[i] +                               // bars on left side
            1 +                                     // current bar
            ( st.empty() ? n-i-1 : st.top()-i-1 )   // bars on right side
        ) * arr[i];                                 // height of current bar
        answer = max(answer, area);                 // maximising the area
        st.push(i);
    }
    
    return answer;
}

/*
APPROACH:
    For each bar just find first smaller bar from its left & right side,
    these smaller bars can not contribute in area for current bar with full height,
    Now just count no. of bars between leftmost & rightmost smaller bars,
    this will be width of react & multiply height of current bar to get area,
    keep recording the max area of rectangle achieved...
*/

int main(){
    long long t; cin>>t; while(t--){
        int n; cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<getMaxArea(arr, n)<<endl;   
    }
	return 0;
}