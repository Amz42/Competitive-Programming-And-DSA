// Question: https://leetcode.com/problems/fruit-into-baskets/
// Solution: https://leetcode.com/submissions/detail/500867871/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        int l = 0, r = 0, types = 0;
        int answer = 0;
        int freq[40001]{0};
        
        while(r<n) {
            freq[tree[r]]++;
            if(freq[tree[r]] == 1)
                types++;
            
            while(l<=r && types>2){
                freq[tree[l]]--;
                if(freq[tree[l]] == 0)
                    types--;
                l++;
            }
            
            answer = max(answer, r-l+1);
                
            r++;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}