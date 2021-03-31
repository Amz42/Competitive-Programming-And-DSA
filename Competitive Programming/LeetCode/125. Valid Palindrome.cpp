// Question: https://leetcode.com/problems/valid-palindrome/
// Solution: https://leetcode.com/submissions/detail/474486374/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        
        for(auto k: s){
            char c = k;
            if(c>='A' && c<='Z') c = (char)((c-'A')+'a');
            if((c>='a' && c<='z') || (c>='0' && c<='9')) a += c;
        }
        
        for(int i=0;i<a.size()/2;i++)
            if(a[i] != a[a.size()-i-1]) return false;
        
        return true;
    }
};

int main(){
    return 0;
}