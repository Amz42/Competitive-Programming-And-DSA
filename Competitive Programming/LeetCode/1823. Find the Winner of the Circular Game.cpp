// Question: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Solution: https://leetcode.com/contest/weekly-contest-236/submissions/detail/479106286/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(set<int>& s, int k, int start){
        int nxt = (start+k-1)%s.size();
        s.erase(next(s.begin(), nxt));
        return nxt;
    }
    
    int findTheWinner(int n, int k) {
        set<int> s;
        for(int i=0;i<n;i++) s.insert(i);
        
        int start = 0;
        while(s.size()>1) start = fun(s, k, start);
        
        return (*s.begin())+1;
    }
};

int main(){
    return 0;
}