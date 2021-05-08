// Question: https://leetcode.com/problems/ugly-number-ii/
// (Set as Heap) Solution-1: https://leetcode.com/submissions/detail/490222049/
// (DP) Solution-2: https://leetcode.com/submissions/detail/490225012/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int nthUglyNumber(int n) {
        set<long long int> s; s.insert(1);
        
        while(true){
            long long int g = *s.begin(); s.erase(s.begin());
            
            if(--n==0)
                return g;
            
            s.insert(g*2);
            s.insert(g*3);
            s.insert(g*5);
        }
    }
};

class Solution2 {
public:
    int nthUglyNumber(int n) {
        long long int dp[n]; dp[0] = 1;
        long long int a = 2, b = 3, c = 5;
        int a1 = 0, b1 = 0, c1 = 0;
        
        for(int i=1;i<n;i++){
            long long int num = min({a, b, c});
            dp[i] = num;
            
            if(a == num) a = 2 * dp[++a1];
            if(b == num) b = 3 * dp[++b1];
            if(c == num) c = 5 * dp[++c1];
        }
        
        return dp[n-1];
    }
};

int main(){
    return 0;
}