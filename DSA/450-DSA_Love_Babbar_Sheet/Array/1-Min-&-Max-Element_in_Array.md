# [GFG Article](https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/)


## Solution 1 - Python
```python
A = [1, 2, 3, 4, 5, 6]
print(A)
print("Min element is",min(A),"Max element is",max(A))
```

## Solution 2 - Java
```java
class Solution {
    public Pair<Long, Long> getMinMax(int[] arr) {
        int mx = Integer.MIN_VALUE;
        int mn = Integer.MAX_VALUE;
        
        for(int i =0; i<arr.length; i++) {
            mx = Math.max(mx, arr[i]);
            mn = Math.min(mn, arr[i]);
        }
        
        return new Pair(mn, mx);
    }
}
```

