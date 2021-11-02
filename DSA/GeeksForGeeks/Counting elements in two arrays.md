### GeeksForGeeks - Counting elements in two arrays

[Question](https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1/)

##### C++

###### [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=e6c109a703da0f1d9f00b0a5199d6cef&pid=700563&user=amanguptarkg6)
```c++
// Time Complexity: O((m+n)*logn)
// Space Complexity: O(1)

class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int a1[], int a2[], int m, int n){
        sort(a2, a2 + n);
        
        vector<int> answer;
        for(int i=0;i<m;i++){
            int l = 0, r = n - 1;
            
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(a2[mid] <= a1[i]) l = mid + 1;
                else r = mid - 1;
            }
            
            answer.push_back(l);
        }
        
        return answer;
    }
};
```