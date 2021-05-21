// Question: https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a2638c6d2391f0b203d3571bda0bc5f9&pid=701209&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
        
    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n){
        int lmin[n], rmax[n];
        
        lmin[0] = arr[0];
        for(int i=1;i<n;i++) lmin[i] = min(lmin[i-1], arr[i]);
        rmax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--) rmax[i] = max(rmax[i+1], arr[i]);
        
        int answer = -1;
        int i = 0, j = 0;
        while(i<n && j<n){
            if(lmin[i] <= rmax[j]){
                answer = max(answer, j-i);
                j++;
            }else
                i++;
        }
        
        return answer;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends