// Question: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Solution: https://leetcode.com/submissions/detail/488404273/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size(), sum = 0;
        int mod[(int)(1e4)] = {0};
        
        for(int i=0;i<n;i++)
            mod[(sum = (((sum + A[i]) % K) + K) % K )]++;
        
        int answer = 0;
        for(int i=0;i<K;i++)
            answer += ((mod[i]*(mod[i]-1))/2);
        answer += mod[0];
        
        return answer;
    }
};

int main(){
    return 0;
}