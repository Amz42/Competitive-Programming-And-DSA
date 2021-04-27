// Question: https://leetcode.com/problems/furthest-building-you-can-reach/
// Solution: https://leetcode.com/submissions/detail/485852583/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long int totsum;
    long long int sum;
    priority_queue<long long int, vector<long long int>,greater<long long int>> pq;
    
    void add(long long int d,long long int ladders){
        pq.push(d);
        sum += d;
        totsum += d;
        if(pq.size()>ladders){ sum -= pq.top(); pq.pop();}
    }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        totsum = sum = 0;
        while(pq.size()>0) pq.pop();
        
        int answer = 0;
        for(int i=1;i<n;i++){
            if(heights[i]>heights[i-1]){ // inclination
                add(heights[i]-heights[i-1], ladders);
                if(
                    bricks >= totsum-sum
                ) answer = i;
                else break;
            }
            answer = i;
        }
        
        return answer;
    }
};

int main(){
    Solution s = *new Solution();
    return 0;
}