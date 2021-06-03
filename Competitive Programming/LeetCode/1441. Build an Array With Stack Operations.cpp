// Question: https://leetcode.com/problems/build-an-array-with-stack-operations/
// Solution: https://leetcode.com/submissions/detail/500007149/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        
        int p = 0;
        for(int i=1; i<=n; i++){
            ans.push_back("Push");
            if(i == target[p]) p++;
            else
                ans.push_back("Pop");
            if(p==target.size()) break;
        }
        
        return ans;
    }
};

int main(){
  return 0;
}