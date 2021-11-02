### GeeksForGeeks - Peak element

[Question](https://practice.geeksforgeeks.org/problems/peak-element/1) 

##### C++

###### [Solution - 1](https://practice.geeksforgeeks.org/viewSol.php?subId=9d35459fb16db80c27a6fdae5f96fb23&pid=700512&) O(n)
```c++
int peakElement(int arr[], int n){
    if(n == 1 || arr[0] > arr[1]) return 0;
    
    for(int i=1; i<n-1 ; i++)
        if(arr[i-1]<arr[i] && arr[i]>arr[i+1])
            return i;
    
    return n - 1;
}
```

###### [Solution - 2](https://practice.geeksforgeeks.org/viewSol.php?subId=8144a79af582d7abcd2d8716a6eab250&pid=700512&user=amanguptarkg6) O(nlogn)
```c++
class Solution{
public:
    int peakElement(int arr[], int n){
        
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(
                (mid == 0 || arr[mid-1] <= arr[mid]) &&
                (mid == n-1 || arr[mid+1] <= arr[mid])
            ) return mid;
            else if(mid > 0 && arr[mid - 1] > arr[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return -1;
    }
};
```