// Question: https://leetcode.com/problems/jump-game-vi/
// Solution: https://leetcode.com/submissions/detail/505557387/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& v, int k) {
        priority_queue<pair<int,int>> pq;
        int n = v.size();
        
        if(n==1) return v[0];
        
        pq.push({v[n-1], n-1});
        for(int i=n-2;i>0;i--) {
            while((pq.top()).second > i+k) pq.pop();
            int e = (pq.top()).first;
            pq.push({v[i]+e, i});
        }
        
        while((pq.top()).second > k) pq.pop();
        return (v[0] + (pq.top()).first);
    }
};

int main(){
  return 0;
}