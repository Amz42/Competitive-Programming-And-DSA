// Question: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
// Solution: https://leetcode.com/submissions/detail/499995367/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int tim[1005] = {0};
        
        for(int i=0;i<n;i++){
            tim[startTime[i]]++;
            tim[endTime[i]+1]--;
        }
        
        for(int i=1;i<1005;i++) tim[i] += tim[i-1];
        
        return tim[queryTime];
    }
};

int main(){
  return 0;
}