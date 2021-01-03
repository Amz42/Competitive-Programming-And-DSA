// Question: https://leetcode.com/problems/next-permutation/
// Solution: https://leetcode.com/submissions/detail/436411214/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print(vector<int> &v){
        cout<<"[";
        
        if(v.size()){
            for(int i=0;i<v.size()-1;i++) cout << v[i] << ",";
            cout<<v[v.size()-1];
        }
        
        cout<<"]";
    }
    
    void nextPermutation(vector<int>& nums) {
        int ptr = nums.size()-1;
        
        // finding first downfall from right to left
        while(ptr>0 && nums[ptr-1] >= nums[ptr]) ptr--;
        if(ptr<=0){
            reverse(nums.begin(),nums.end());
            print(nums);
            return;
        }
        
        ptr--;
        
        int index,element = INT_MAX;
        for(int i=ptr+1;i<nums.size();i++){
            if(nums[ptr]<nums[i] && nums[i]<element){
                element = nums[i];
                index = i;
            }
        }
        
        swap(nums[ptr],nums[index]);
        sort(nums.begin()+ptr+1, nums.end());
        print(nums);
    }
};