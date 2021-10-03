### Smallest Positive Integer that can not be represented as Sum

##### C++

```c++
// Article: https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
// Question: https://practice.geeksforgeeks.org/problems/b6b608d4eb1c45f2b5cace77c4914f302ff0f80d/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=bd6c2366e1c276a07ba343798093915d&pid=706045&user=amanguptarkg6

class Solution{
public:
    long long smallestpositive(vector<long long> arr, int n){
        // code here
        
        sort(arr.begin(), arr.end());
        long long answer = 1;
        for(int i=0; i<n && arr[i] <= answer; i++)
            answer += arr[i];
        
        return answer;
    }
};
```