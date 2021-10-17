### GeeksForGeeks - Subset Sums

[Question](https://practice.geeksforgeeks.org/problems/subset-sums2234/1)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=0942894567f3561d553d7f72c7f68f53&pid=704723&user=amanguptarkg6)

##### C++
```c++
class Solution{
    void fun(vector<int>&answer, vector<int>&a, int sum, int start){
        answer.push_back(sum);
        for(int i=start;i<a.size();i++)
            fun(answer, a, sum + a[i], i+1);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int>answer;
        fun(answer, arr, 0, 0);
        return answer;
    }
};
```