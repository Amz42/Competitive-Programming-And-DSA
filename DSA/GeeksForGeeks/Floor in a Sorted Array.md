### GeeksForGeeks - Floor in a Sorted Array

[Question](https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1/)

##### C++

###### [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=e0143b7a95ba1992f12da9be39f00a98&pid=701222&user=amanguptarkg6)
```c++
// Time Complexity: O(logn)
// Space Complexity: O(1)
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        long long l = 0, r = n;
        while(l < r){
            long long mid = l + (r - l) / 2;
            
            if(v[mid] > x) r = mid;
            else l = mid + 1;
        }
        
        return r - 1;
    }
};
```