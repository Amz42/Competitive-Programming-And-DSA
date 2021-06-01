// Question: https://leetcode.com/problems/beautiful-array/
// Solution: https://leetcode.com/submissions/detail/500429725/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> answer = {1};
        
        while(answer.size() != n){
            vector<int> tmp;
            for(auto k: answer)
                if(k*2-1<=n)
                    tmp.push_back(k*2-1);
            for(auto k: answer)
                if(k*2<=n)
                    tmp.push_back(k*2);
            answer = tmp;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}