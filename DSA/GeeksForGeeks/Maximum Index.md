### Maximum Index

```c++
// Question: https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f52ff2b4fba792844ec8442b38b5ca4d&pid=701209&user=amanguptarkg6

class Solution{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) {
        int minL[n], maxR[n];
        
        minL[0] = a[0];
        for(int i=1; i<n; i++) minL[i] = min(minL[i-1], a[i]);
        
        maxR[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--) maxR[i] = max(maxR[i+1], a[i]);
        
        int answer = 0;
        
        int l = 0, r = 0;
        
        while(r < n && l < n){
            while(r+1 < n && maxR[r + 1] >= minL[l]) r++;
            if(maxR[r] >= minL[l])
                answer = max(answer, r - l);
            l++;
        }
        
        return answer;
    }
};
```