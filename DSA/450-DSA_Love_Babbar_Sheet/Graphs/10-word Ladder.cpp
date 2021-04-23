// Question: https://leetcode.com/problems/word-ladder/
// Solution: https://leetcode.com/submissions/detail/484176654/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isPossible = false;
        unordered_set<string> myset;
        for(auto k: wordList){
            if(endWord.compare(k)==0)
                isPossible = true;
            myset.insert(k);
        }
        
        if(!isPossible) return 0;
        
        int level = 1;
        queue<string> q; q.push(beginWord);
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                string s = q.front(); q.pop();
                
                // picking up an index of current string
                for(int j=0;j<s.size();j++){
                    string ss = s;
                    // transforming that index
                    for(char c='a';c<='z';c++){
                        if(ss[j]==c) continue;
                        ss[j] = c;
                        
                        // if transformation resulted in endWord
                        if(ss.compare(endWord) == 0)
                            return level+1;
                        
                        // if transformation is present in myset
                        if(myset.find(ss)!=myset.end())
                            q.push(ss), myset.erase(ss);
                    }
                }
            }
            level++;
        }
        
        return 0;
    }
};

int main(){
    return 0;
}