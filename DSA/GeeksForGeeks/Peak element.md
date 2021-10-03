### Peak element

```c++
// Question: https://practice.geeksforgeeks.org/problems/peak-element/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=9d35459fb16db80c27a6fdae5f96fb23&pid=700512&user=amanguptarkg6

int peakElement(int arr[], int n){
    if(n == 1 || arr[0] > arr[1]) return 0;
    
    for(int i=1; i<n-1 ; i++)
        if(arr[i-1]<arr[i] && arr[i]>arr[i+1])
            return i;
    
    return n - 1;
}
```