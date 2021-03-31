// Question: https://leetcode.com/problems/first-unique-character-in-a-string/
// Solution: https://leetcode.com/submissions/detail/474752173/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int a[26] = {0};
        for(auto k: s) a[k-'a']++;
        
        int j = 0;
        for(auto k: s){
            if(a[k-'a']==1) return j;
            j++;
        }
        
        return -1;
    }
};

int main(){
    return 0;
}