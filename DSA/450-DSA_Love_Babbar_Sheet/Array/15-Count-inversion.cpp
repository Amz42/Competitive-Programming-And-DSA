// Question: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=8984c22e36b857be56cf426a0914e90d&pid=701226&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long int answer = 0;

void merge_sort(long long a[], int l, int mid, int r){
    int i,j,k;
    int L = mid-l+1;                        // size of left array
    int R = r-mid;                          // size of right array
    
    long long left[L], right[R];                  // making left & right array
    
    for(i=0;i<L;i++) left[i] = a[l+i];      // copy left side elements in left array
    for(j=0;j<R;j++) right[j] = a[mid+1+j];   // copy right side elements in right array
    
    i = j = 0;                          // setting index counter for left, right & main array
    k = l;
    
    // sorting & merging left & right arrays
    while(i<L && j<R){
        if(left[i]<=right[j]) a[k++] = left[i++];
        else answer += L-i, a[k++] = right[j++];
    }
    
    // filling remaining elements of left & right array
    while(i<L) a[k++] = left[i++];
    while(j<R) a[k++] = right[j++];
}

void divide(long long a[], int l, int r){
    if(l<r){
        int mid = l + (r - l) / 2;  // finding the mid index to divide array into 2 halves
        divide(a,l,mid);            // further divide left part
        divide(a,mid+1,r);          // further divide right part
        merge_sort(a,l,mid,r);      // merge both left & right parts
    }
}

long long int inversionCount(long long arr[], long long N){
    divide(arr, 0, N-1);
    long long int ans = answer;     // taking answer from global variable
    answer = 0;                     // resetting global variable to zero
    return ans;
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends