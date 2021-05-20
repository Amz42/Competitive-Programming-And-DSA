// Question: https://www.codingninjas.com/codestudio/problems/search-for-integers-with-given-difference-and-at-given-distance_920504

#include <bits/stdc++.h>
using namespace std;

vector<int> indicesAtGivenDistance(vector<int>& a, int n, int k, int m){
	set<pair<int,int>> s;
    
    vector<int> answer;
    for(int i=0;i<n;i++){
        auto it = s.lower_bound({ (a[i]-m) , -1});
        
        if(it!=s.end()){
            auto g = *it;
            if( abs(g.first-a[i])<=m ){
                answer.push_back(g.second);
                answer.push_back(i);
                break;
            }
        }
        
        if(i-k>=0){
            // removing element from the window
            it = s.lower_bound({a[i-k], -1});
            s.erase(it);
        }
        // pushing current element
        s.insert({a[i], i});
    }
    
    return answer;
}