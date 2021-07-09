// Question: https://leetcode.com/problems/keys-and-rooms/
// Solution: https://leetcode.com/submissions/detail/519958806/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool> vis(n, false);
        
        queue<int> q; q.push(0); vis[0] = true;
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            for(int k: rooms[node])
                if(vis[k] == false){
                    vis[k] = true;
                    q.push(k);
                }
        }
        
        for(int i=0;i<n;i++)
            if(vis[i] == false)
                return false;
        
        return true;
    }
};

int main(){
  return 0;
}