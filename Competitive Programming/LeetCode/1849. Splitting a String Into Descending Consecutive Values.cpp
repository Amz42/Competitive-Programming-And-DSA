// Question: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
// Solution: https://leetcode.com/submissions/detail/487879796/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool answer;
    void fun(int index, string&s,long long int last, int cut){
        if(index==s.size()){
            if(cut>1) answer = true;
            return;
        }
        
        for(int len=1;len+index<=s.size() && len<=19;len++){
            unsigned long long int num = stoull(s.substr(index, len));
            if(last==-1 || last-1==num)
                fun(index+len, s, num, cut+1);
        }
    }
public:
    bool splitString(string s) {
        answer = false;
        
        fun(0, s, -1LL, 0);
        
        return answer;
    }
};

int main(){
    return 0;
}