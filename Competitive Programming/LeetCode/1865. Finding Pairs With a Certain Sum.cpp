// Question: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
// Solution: https://leetcode.com/submissions/detail/494095908/

#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
    vector<int> b;
    unordered_map<int,int> mp,mp1;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        b = nums2;
        for(auto k: nums1) mp1[k]++;
        for(auto k: nums2) mp[k]++;
    }
    
    void add(int index, int val) {
        int e = b[index];
        mp[e]--; mp[e+val]++;
        b[index] = e+val;
    }
    
    int count(int tot) {
        int answer = 0;
        for(auto k: mp1) answer += (k.second * mp[tot-k.first]);
        return answer;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main(){
    return 0;
}