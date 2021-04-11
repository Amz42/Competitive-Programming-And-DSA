// Question: https://leetcode.com/problems/sign-of-the-product-of-an-array/
// Solution: https://leetcode.com/contest/weekly-contest-236/submissions/detail/479096435/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int a = 1;
        for(auto k: nums){
            if(k<0) a*=-1;
            if(k==0) a*=0;
        }
        
        if(a>0) return 1;
        else if(a<0) return -1;
        else return 0;
    }
};

int main(){
    return 0;
}