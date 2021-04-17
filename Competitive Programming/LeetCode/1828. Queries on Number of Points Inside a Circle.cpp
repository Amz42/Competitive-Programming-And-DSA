// Question: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
// Solution: https://leetcode.com/contest/biweekly-contest-50/submissions/detail/481745558/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool fun(int px, int py, int cx, int cy, int r){
        if( ((px-cx)*(px-cx) + (py-cy)*(py-cy)) <= r*r ) return true;
        return false;
    }
public:
    vector<int> countPoints(vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<int> answer;
        for(int i=0;i<q.size();i++){
            int count = 0;
            for(int j=0;j<p.size();j++){
                if( fun(p[j][0],p[j][1],q[i][0],q[i][1],q[i][2]) ) count++;
            }
            answer.push_back(count);
        }
        
        return answer;
    }
};

int main(){
    return 0;
}