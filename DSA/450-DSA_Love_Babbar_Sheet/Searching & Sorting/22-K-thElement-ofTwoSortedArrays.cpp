// Question: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=65c6fd22214f7aa6e5595305a910e686&pid=703253&user=amanguptarkg6


#include <bits/stdc++.h>
using namespace std;

/*
APPROACH:
    by using merge sort type technique,
    iterate for k elements &
    just keep noting the last element popped from array
*/

class Solution{
    public:
    int kthElement(int a1[], int a2[], int n, int m, int k){
        int i = 0, j = 0, last = min(a1[0], a2[0]);
        
        for(int g=0;g<k;g++){
            if(i<n && j<m) last = ( a1[i]<a2[j] ? a1[i++] : a2[j++] );
            else last = ( i==n ? a2[j++] : a1[i++] );
        }
        
        return last;
    }
};

// VVVVVVVVVVVV      IMPORTANT
//////////////////////////////////////////////////////////////////////////   Solution 2
//////////////////////////////////////////////////////////////////////////   O(log(n+m))
class Solution2{
    public:
    
    int kth(int k, int al, int ar, int bl, int br, int a[], int b[]){
        if(al >= ar) return b[bl+k]; // no element left in a[]
        if(bl >= br) return a[al+k]; // no element left in b[]
        
        int midA = (ar-al) / 2;
        int midB = (br-bl) / 2;
        
        if(midA + midB < k){ // k exist in right part
            
            // left part of b[] is discarded
            if(a[al+midA] > b[bl+midB])
                return kth(k - (midB+1), al, ar, bl+midB+1, br, a, b);
                
            // left part of a[] is discarded
            else 
                return kth(k - (midA+1), al+midA+1, ar, bl, br, a, b);
            
        }else{ // k exist in left part
            
            // right part of a[] is discarded
            if(a[al+midA]>b[bl+midB])
                return kth(k, al, al+midA, bl, br, a, b);
             
             // right part of b[] is discarded
            else
                return kth(k, al, ar, bl, bl+midB, a, b);
        }
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        return kth(k-1, 0, n, 0, m, arr1, arr2);
    }
};
//////////////////////////////////////////////////////////////////////////   O(log(n+m))
//////////////////////////////////////////////////////////////////////////   Solution 2
// VVVVVVVVVVVV      IMPORTANT

int main(){
	int t; cin>>t; while(t--){
		int n,m,k; cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++) cin>>arr1[i];
		for(int i=0;i<m;i++) cin>>arr2[i];
		Solution ob; cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}