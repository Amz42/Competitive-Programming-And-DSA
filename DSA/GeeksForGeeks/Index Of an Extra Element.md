### GeeksForGeeks - Index Of an Extra Element

[Question](https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/1/)

##### C++

###### [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=0af285c5cd68702fc2c14c136f704948&pid=700517&user=amanguptarkg6)
```c++
// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(a[mid] == b[mid])
                l = mid + 1;
            else
                r = mid;
        }
        
        return l;
    }
};
```