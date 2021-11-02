### GeeksForGeeks - Missing number in array 

[Question](https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=d0e31cca78450aa8d64ebcb95ae4b087&pid=701889&user=amanguptarkg6)

##### C++
```c++
class Solution{
  public:
    int MissingNumber(vector<int>& v, int n) {
        return (n * (n+1) / 2) - accumulate(v.begin(), v.end(), 0);
    }
};
```