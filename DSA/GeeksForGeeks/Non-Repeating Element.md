### Non-Repeating Element

##### C++

```c++
// Question: https://practice.geeksforgeeks.org/problems/non-repeating-element3958/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=0d3209adfc79eda333951fb6b425a655&pid=702696&user=amanguptarkg6

class Solution{
    public:
    int firstNonRepeating(int arr[], int n){
        // Complete the function
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        for(int i=0;i<n;i++)
            if(mp[arr[i]] == 1)
                return arr[i];
        
        return 0;
    } 
  
};
```