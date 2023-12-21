## [Reverse The Array](https://www.codingninjas.com/studio/problems/reverse-the-array_1262298)
### [GFG Article](https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/)
### [Coding Ninjas](https://www.codingninjas.com/studio/problems/reverse-the-array_1262298)

#### Solution: Java
```java
import java.util.*;
import java.io.*;
import java.util.ArrayList;

public class Solution {
    public static void reverseArray(ArrayList<Integer> arr, int m) {
        int l = m + 1;
        int r = arr.size() - 1;

        while(l < r) {
            Collections.swap(arr, l, r);
            l++;
            r--;
        }
    }
}
```