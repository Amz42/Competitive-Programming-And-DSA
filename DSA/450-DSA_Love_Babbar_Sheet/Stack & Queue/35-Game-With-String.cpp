// Question: https://practice.geeksforgeeks.org/problems/game-with-string4100/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=e617fce2a1509cbe659215f672e48d53&pid=705091&user=amanguptarkg6


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minValue(string s, int k){
        int freq[26]={0};
        for(int i=0;i<(int)s.size();i++) freq[s[i]-'a']++;
        
        priority_queue<int> pq;
        for(int i=0;i<26;i++) pq.push(freq[i]);
        
        while(k){
            int val = pq.top(); pq.pop();
            int toRemove = min(k, (pq.size() ? val-pq.top()+1 : val ));
            val -= toRemove;
            k -= toRemove;
            pq.push(val);
        }
        
        int answer = 0;
        while(!pq.empty()){ answer += (pq.top()*pq.top()); pq.pop();}
        return answer;
    }
};

int main(){
    int t; cin>>t; while(t--){
        string s; int k; cin>>s>>k;
        Solution ob; cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}