// Question: https://www.codingninjas.com/codestudio/problems/rearrange-string_985247

#include<bits/stdc++.h>
using namespace std;

string reArrangeString(string str) {
    int freq[26] = {0};
    for(auto k: str) freq[k-'a']++;
    
    priority_queue<pair<int,char>, vector<pair<int,char>>> q;
    for(int i=0;i<26;i++)
        if(freq[i]>0)
            q.push({freq[i], (char)('a'+i)});
    
    string answer = "";
    while(q.size()>1){
        auto x = q.top(); q.pop();
        auto y = q.top(); q.pop();
        
        answer = answer + x.second + y.second;
        x.first--; y.first--;
        if(x.first>0) q.push(x);
        if(y.first>0) q.push(y);
    }
    
    if(q.size()){
        if(q.top().first>1) return "NO SOLUTION";
        auto x = q.top(); q.pop();
        x.first--;
        answer += x.second;
    }
    
    return answer;
}

int main(){
  return 0;
}