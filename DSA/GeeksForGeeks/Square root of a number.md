### GeeksForGeeks - Square root of a number

[Question](https://practice.geeksforgeeks.org/problems/square-root/1/#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=ba0b647ad919c120e7768dab679f8673&pid=700226&user=amanguptarkg6)

##### C++
```c++
class Solution{
  public:
    long long int floorSqrt(long long int x) {
        long long int l = 0, r = x;
        
        while(l <= r){
            long long int mid = l + (r - l) / 2;
            if(mid * mid <= x) l = mid + 1;
            else r = mid - 1;
        }
        
        return l - 1;
    }
};
```