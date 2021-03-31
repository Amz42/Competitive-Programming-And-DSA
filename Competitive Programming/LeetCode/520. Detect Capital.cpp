// Question: https://leetcode.com/problems/detect-capital/
// Solution: https://leetcode.com/submissions/detail/474483484/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitals = 0;
        for(auto k: word)
            if(k>='A' && k<='Z') capitals++;
        
        if (
            capitals == 0 ||
            capitals == word.size() ||
            (capitals == 1 && word[0]>='A' && word[0]<='Z')
        ) return true;
        return false;
    }
};

int main(){
    return 0;
}