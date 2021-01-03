// Question: https://leetcode.com/problems/merge-intervals/
// Solution: https://leetcode.com/submissions/detail/433787069/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> & intervals) {
        vector<vector<int> > v;
        sort(intervals.begin(), intervals.end());
        int s=intervals[0][0], e=intervals[0][1];
        for(auto k:intervals){
            int ss=k[0],ee=k[1];
            if(ss<=e){
                e=max(e,ee);
            }else{
                vector<int> a={s,e};
                v.push_back(a);
                s=ss,e=ee;
            }
        }
        vector<int> a={s,e};
        v.push_back(a);
        return v;
    }
};