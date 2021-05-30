// Question: https://leetcode.com/problems/find-center-of-star-graph/
// Solution: https://leetcode.com/submissions/detail/499981242/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x = edges[0][0], y = edges[0][1];
        int a = edges[1][0], b = edges[1][1];
        
        if(x == a || x == b) return x;
        return y;
    }
};

int main(){
  return 0;
}