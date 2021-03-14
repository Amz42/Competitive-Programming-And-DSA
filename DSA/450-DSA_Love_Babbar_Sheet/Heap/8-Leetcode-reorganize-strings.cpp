// Question: https://leetcode.com/problems/reorganize-string/submissions/
// Solution: https://leetcode.com/submissions/detail/467376707/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int,int>> q;
        
        int a[26] = {0};
        for(auto k: S) a[k-'a']++;
        
        for(int i=0;i<26;i++) if(a[i]>0) q.push(make_pair(a[i], i));
        
        string answer = "";
        while(q.size()>1){
            auto k = q.top(); q.pop();
            auto g = q.top(); q.pop();
            
            answer = answer + (char)(k.second + 'a') + char(g.second + 'a');
            k.first--, g.first--;
            
            if(k.first) q.push(k);
            if(g.first) q.push(g);
        }
        
        if(q.size()){
            auto k = q.top(); q.pop();
            if(k.first>1) return "";
            else answer += (char)(k.second+'a');
        }
        
        return answer;
    }
};

int main(){
    Solution s;
    cout<<s.reorganizeString("aaab")<<endl; // answer = ""
    cout<<s.reorganizeString("aab")<<endl; // answer = "aba"
    return 0;
}