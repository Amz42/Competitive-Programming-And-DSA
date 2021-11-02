### GeeksForGeeks - Search an element in sorted and rotated array

[Question](https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array0959/1/)

##### C++

###### [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=9c2cb51138312fbf54e725dde64eb724&pid=702054&user=amanguptarkg6)
```c++
// Time Complexity: O(logn)
// Space Complexity: O(1)
int Search(vector<int> a, int K) {
    int n = a.size();
    int l = 0, r = n - 1;
    
    while(l <= r){
        int mid = l + (r - l) / 2;
        
        if(a[mid] == K)
            return mid;
        else if(a[l] < a[mid]){
            // straight increment on left side
            if(a[l] <= K && K < a[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }else{
            // straight increment on right side
            if(a[mid] < K && K <= a[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    
    return -1;
}
```