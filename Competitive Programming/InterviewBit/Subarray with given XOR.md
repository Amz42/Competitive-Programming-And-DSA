### Subarray with given XOR

[Question](https://www.interviewbit.com/problems/subarray-with-given-xor/)

##### C++

```c++
int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> s; s[0] = 1;
    
    int answer = 0, xr = 0;
    for(auto k: A){
        xr^=k;
        answer += s[xr^B];
        s[xr]++;
    }

    return answer;
}
```