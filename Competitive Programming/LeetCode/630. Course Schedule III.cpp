// Question: https://leetcode.com/problems/course-schedule-iii/
// Solution: https://leetcode.com/submissions/detail/488839928/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& co) {
        int n = co.size();
        sort(co.begin(), co.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        
        priority_queue<int> q;
        int time = 0;
        for(int i=0;i<n;i++){
            if(time+co[i][0]<=co[i][1])
                time += co[i][0], q.push(co[i][0]);
            else if(q.size()>0 && q.top()>co[i][0]){
                time -= q.top();
                time += co[i][0];
                q.push(co[i][0]);
                q.pop();
            }
        }
        
        return q.size();
    }
};

int main(){
    return 0;
}