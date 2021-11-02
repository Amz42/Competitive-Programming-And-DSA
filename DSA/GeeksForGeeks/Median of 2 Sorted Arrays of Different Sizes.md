### GeeksForGeeks - Median of 2 Sorted Arrays of Different Sizes

[Question](https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1/)

##### C++

###### [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=39dcc0cfd6219c32d6d287cb63018422&pid=702044&user=amanguptarkg6)
```c++
// Time Complexity: O(min(logn, logm))
// Space Complexity: O(1)

class Solution{
    public:
    double MedianOfArrays(vector<int>& a, vector<int>& b){
        int n = a.size();
        int m = b.size();
        
        if(n > m)
            return MedianOfArrays(b, a);
            
        int l = 0, r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int lAsize = mid;
            int lBsize = (n + m + 1) / 2 - lAsize;
            
            int leftA = lAsize > 0 ? a[lAsize - 1] : INT_MIN;
            int leftB = lBsize > 0 ? b[lBsize - 1] : INT_MIN;
            int rightA = lAsize < n ? a[lAsize] : INT_MAX;
            int rightB = lBsize < m ? b[lBsize] : INT_MAX;
            
            if(leftA <= rightB && leftB <= rightA){
                return (n + m) % 2 == 0
                    ? ( max(leftA, leftB) + min(rightA, rightB) ) / 2.0
                    : max(leftA, leftB);
            } else if(leftA > rightB)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return 0.0;
    }
};
```