// Question: https://leetcode.com/problems/iterator-for-combination/
// (BackTracking) Solution1: https://leetcode.com/submissions/detail/474689900/
// (BitMasking) Solution2: https://leetcode.com/submissions/detail/474682968/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 | BackTracking
class CombinationIterator {
    int ptr;
    vector<string> comb;
    void fun(string& s, int index,int& len, string res){
        if(res.size() == len){
            comb.push_back(res);
            return;
        }
        if(index == s.size()) return;
        
        fun(s, index+1, len, res+s[index]);
        fun(s, index+1, len, res);
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        comb.clear(); ptr = 0;
        fun(characters, 0, combinationLength, "");
    }
    
    string next() {
        return comb[ptr++];
    }
    
    bool hasNext() {
        return (ptr<comb.size());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


// Solution 2 | BitMasking
class CombinationIterator {
    map<string, int> comb;
    map<string, int> :: iterator ptr;
public:
    CombinationIterator(string s, int len) {
        comb.clear();
        
        int n = s.size();
        int mask = 1<<n;
        
        for(int i=1;i<mask;i++){
            int current = i;
            int j = 0;
            string a = "";
            
            while(current){
                if(current&1) a += s[j];
                current >>= 1;
                j++;
            }
            
            if(a.size()==len) comb[a]++;
        }
        ptr = comb.begin();
    }
    
    string next() {
        return (ptr++)->first;
    }
    
    bool hasNext() {
        return (ptr != comb.end());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */



int main(){
    return 0;
}