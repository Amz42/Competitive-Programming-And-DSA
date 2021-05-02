// Question: https://leetcode.com/problems/k-concatenation-maximum-sum/
// Solution: https://leetcode.com/submissions/detail/487980472/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1e9+7;
    long long kadane(vector<int>& arr, int k){
        int n = arr.size();
        long long meh = 0, KDN = 0;
        for(int i=0;i<n*k;i++){
            meh += arr[i%n];
            KDN = max(KDN, meh);
            meh = max(meh, 0LL);
        }
        
        return KDN % MOD;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long total = 0;
        
        for(int i=0;i<arr.size();i++) total = (total + arr[i]) % MOD;
        
        if(k==1) return kadane(arr, 1);
        if(total<=0) return kadane(arr, 2);
        return max(kadane(arr, 2) + (total * (k-2)) % MOD, 0LL);
    }
};

int main(){
    return 0;
}