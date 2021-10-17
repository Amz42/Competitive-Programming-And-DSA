### GeeksForGeeks - Longest Sub-Array with Sum K

[Question](https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=79a40eed68aafddc9caf82665c677be2&pid=703043&user=amanguptarkg6)
| [Article](https://www.geeksforgeeks.org/longest-sub-array-sum-k/)

##### C++
```c++
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K){
        unordered_map<int, int> mp; mp[0] = 0;
        
        int sum = 0, answer = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(mp.find(sum - K) != mp.end())
                answer = max(answer, i+1 - mp[sum - K]);
            if(mp.find(sum) == mp.end())
                mp[sum] = i+1;
        }
          
        return answer;
    } 
};
```