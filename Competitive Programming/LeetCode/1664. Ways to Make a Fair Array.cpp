// Question: https://leetcode.com/problems/ways-to-make-a-fair-array/
// Solution: https://leetcode.com/submissions/detail/490234715/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        // odd total & even total
        int odt = 0, evt = 0;
        
        for(int i=0;i<n;i++) (i&1 ? odt += nums[i] : evt += nums[i]);
        
        int answer = 0;
        int pref_ev = 0, pref_od = 0;
        for(int i=0;i<n;i++){
            int suff_od, suff_ev;
            if(i&1){
                suff_ev = odt - pref_od - nums[i];
                suff_od = evt - pref_ev;
            }else{
                suff_ev = odt - pref_od;
                suff_od = evt - pref_ev - nums[i];
            }
            
            if(pref_ev + suff_ev == pref_od + suff_od)
                answer++;
                
            (i&1 ? pref_od += nums[i] : pref_ev += nums[i]);
        }
        
        return answer;
    }
};

int main(){
    return 0;
}