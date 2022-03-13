## GeeksForGeeks - Minimum Platforms

### [Question](https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1)

### [C++ Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=665f3bb3a4cc388299aa7627ec3cbb16&pid=701368&user=amanguptarkg6)
```c++
int findPlatform(int arr[], int dep[], int n){
	sort(arr, arr+n);
	sort(dep, dep+n);
	
	int aptr = 0, dptr = 0, current_platforms = 0, answer = 0;
	while(aptr<n){
	    if(dep[dptr]<arr[aptr]) dptr++, current_platforms--;
	    else aptr++, current_platforms++;
	    
	    answer = max(answer, current_platforms);
	}
	
	return answer;
}
```

### [Java Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=22355886d3d3c7074a94e1c033a73ff4&pid=701368&user=amanguptarkg6)
```java
class Solution {
    static int findPlatform(int arr[], int dep[], int n) {
        int minimumPlatformsRequired = 0;
        int currentPlatformsOccupied = 0;
        int arrIter = 0;
        int depIter = 0;
        
        Arrays.sort(arr);
        Arrays.sort(dep);
        
        while(arrIter < n) {
            if(arr[arrIter] <= dep[depIter]) {
                arrIter += 1;
                currentPlatformsOccupied += 1;
            } else {
                depIter += 1;
                currentPlatformsOccupied -= 1;
            }
            
            minimumPlatformsRequired = Math.max(
                minimumPlatformsRequired,
                currentPlatformsOccupied
            );
        }
        
        return minimumPlatformsRequired;
    }
}
```