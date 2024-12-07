## [Maximum difference of zeros and ones in binary string](https://www.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1)

#### Solution: Java (Kadane's Algo)
```java
class Solution {
    int maxSubstring(String S) {
        int value = 0;
        int answer = -1;
        
        for (char c: S.toCharArray()) {
            int current = (c == '1' ? -1 : 1);
            value = Math.max(value + current, current);
            answer = Math.max(answer, value);
        }
        
        return answer;
    }
}
```