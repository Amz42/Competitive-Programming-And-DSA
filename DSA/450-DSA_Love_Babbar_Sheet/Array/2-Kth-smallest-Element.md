## [Kth smallest element](https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1)

#### Solution 1: C++
```c++
int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    int freq[100001]={0};
    for(int i=l;i<=r;i++) freq[arr[i]]++;
    
    int sum=0;
    for(int i=0;i<100001;i++){
        if(sum+freq[i]<k) sum += freq[i];
        else{
            return i;
            break;
        }
    }
}
```

#### Solution 2: Java
```java
class Solution {
    public static int kthSmallest(int[] arr, int l, int r, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<Integer>(Collections.reverseOrder());
        
        for(int i = l; i <= r; i++) {
            heap.add(arr[i]);
            if(heap.size() > k) heap.poll();
        }
        
        return heap.peek();
    } 
}
```
