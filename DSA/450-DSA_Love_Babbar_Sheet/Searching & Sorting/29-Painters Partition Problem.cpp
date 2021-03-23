// Question: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b0784b1c1003dd161d215d314a98e52a&pid=701723&user=amanguptarkg6

// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution {
    bool is_valid(int a[], int n, int m, int mx){
        int sum = 0, students = 1;
        
        for(int i=0;i<n;i++){
            sum += a[i];
            if(sum>mx) ++students, sum = a[i];
            if(students>m) return false;
        }
        
        return true;
    }
    public:
    int findPages(int arr[], int n, int m){
        if(n<m) return -1;
        
        int l = INT_MIN, r = 0;
        for(int i=0;i<n;i++){
            l = max(l, arr[i]);             // finding max value
            r += arr[i];                    // calculating sum of all elements
        }
        
        int answer = INT_MAX;
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(is_valid(arr, n, m, mid)){
                answer = mid;               // minimizing the answer
                r = mid-1;
            }else l = mid+1;
        }
        
        return answer;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends