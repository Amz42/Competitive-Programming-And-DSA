### GeeksForGeeks - Find Transition Point

[Question](https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=8a740d7eab1d6be5338599414cd46236&pid=700194&user=amanguptarkg6)

##### C++
```c++
int transitionPoint(int a[], int n) {
    int l = 0, r = n;
    
    while(l < r){
        int mid = l + (r - l) / 2;
        if(a[mid] == 0) l = mid + 1;
        else r = mid;
    }
    
    return l == n ? -1 : l;
}
```