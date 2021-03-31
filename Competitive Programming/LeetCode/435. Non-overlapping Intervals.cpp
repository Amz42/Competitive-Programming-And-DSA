// Question: https://leetcode.com/problems/non-overlapping-intervals/
// Solution: https://leetcode.com/submissions/detail/474702895/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int removed = 0;
        vector<pair<int,int>> v;
        for(auto k: intervals)
            v.push_back({k[0], k[1]});
        
        sort(v.begin(), v.end());
        
        int l = 0, r = 1;
        while(r<n){
            if(v[l].second <= v[r].first){ // non-overlapping
                l = r;
                r++;
            }else if(v[l].second > v[r].first){ // overlapping
                if(v[l].second>v[r].second){ // segment 'l' will end later
                    l = r;
                    r++;
                }else{ // segment 'r' will end later
                    r++;
                }
                removed++;
            }
        }
        
        return removed;
    }
};

int main(){
    return 0;
}