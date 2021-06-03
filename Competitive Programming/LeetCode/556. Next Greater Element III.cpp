// Question: https://leetcode.com/problems/next-greater-element-iii/
// Solution: https://leetcode.com/submissions/detail/499918835/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool not_possible;
    void nextPermutation(string &nums) {
        int ptr = nums.size()-1;
        
        // finding first downfall from right to left
        while(ptr>0 && nums[ptr-1] >= nums[ptr]) ptr--;
        if(ptr<=0){
            not_possible = true;
            return;
        }
        
        ptr--;
        
        int index; char element = (char)('9'+1);
        for(int i=ptr+1;i<nums.size();i++){
            if(nums[ptr]<nums[i] && nums[i]<element){
                element = nums[i];
                index = i;
            }
        }
        
        swap(nums[ptr], nums[index]);
        sort(nums.begin()+ptr+1, nums.end());
    }
public:
    int nextGreaterElement(int n) {
        not_possible = false;
        string s = to_string(n);
        nextPermutation(s);
        
        long long int ans = stoll(s);
        
        if(ans>INT_MAX || not_possible)
            return -1;
        
        return (int)(ans);
    }
};

int main(){
  return 0;
}