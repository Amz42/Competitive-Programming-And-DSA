// Question: https://leetcode.com/problems/jump-game-iii/
// Solution: https://leetcode.com/submissions/detail/474419978/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q; q.push(start);
        bool vis[(int)(5*1e4+2)] = {0}; vis[start] = 1;
        
        while(!q.empty()){
            int g = q.front(); q.pop();
            if(arr[g]==0) return true;
            if(g+arr[g] < arr.size() && !vis[g+arr[g]]){
                q.push(g+arr[g]);
                vis[g+arr[g]] = 1;
            }
            
            if(g-arr[g] >= 0 && !vis[g-arr[g]]){
                q.push(g-arr[g]);
                vis[g-arr[g]] = 1;
            }
        }
        
        return false;
    }
};

int main(){
    return 0;
}