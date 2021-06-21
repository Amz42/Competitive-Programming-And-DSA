// Question: https://leetcode.com/problems/remove-covered-intervals/
// Solution: https://leetcode.com/submissions/detail/511096536/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [&](vector<int>& a, vector<int>& b){
            return (
                a[0] != b[0]
                ? (a[0] < b[0])
                : (a[1] > b[1])
            );
        });
        
        int s = v[0][0];
        int e = v[0][1];
        int answer = 1;
        
        for(int i=1;i<v.size();i++){
            if( !(s<=v[i][0] && v[i][1] <= e) )
                s = v[i][0],
                e = v[i][1],
                answer++;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}