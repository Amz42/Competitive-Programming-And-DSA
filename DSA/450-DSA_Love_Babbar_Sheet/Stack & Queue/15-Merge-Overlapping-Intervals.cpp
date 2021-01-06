// Question: https://practice.geeksforgeeks.org/problems/overlapping-intervals4919/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=9f0b7591d242ca44f733c2bac5d9c636&pid=702036&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> , int);

int main(){
    int t; cin>>t; while(t--){
        vector<pair<int,int> > arr,res;
        int n,x,y; cin>>n;

        for(int i=0;i<n;i++) cin>>x>>y, arr.push_back(make_pair(x,y));
        
        res = overlappedInterval(arr,n);
        for(int i=0;i<res.size();i++) cout << res[i].first << " " << res[i].second << " " ;
        cout<<endl;
    }
}


////////////////////////////////////////////////////////////////////////////// GFG Solution
vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    sort(vec.begin(),vec.end());
    
    vector<pair<int,int>> answer;
    int i=0;
    while(i<n){
        int start = vec[i].first;
        int finish = vec[i].second;
        
        bool merged = false;
        while(i+1<n && vec[i+1].first<=finish){
            finish = max(finish, vec[i+1].second);
            i++;
            merged;
        }
        
        answer.push_back({start,finish});
        if(!merged) i++;
    }
    
    return answer;
}


////////////////////////////////////////////////////////////////////////////// LeetCode Solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > v;
        sort(intervals.begin(), intervals.end());
        int s=intervals[0][0], e=intervals[0][1];
        for(auto k:intervals){
            int ss=k[0],ee=k[1];
            if(ss<=e){
                e=max(e,ee);
            }else{
                vector<int> a={s,e};
                v.push_back(a);
                s=ss,e=ee;
            }
        }
        vector<int> a={s,e};
        v.push_back(a);
        return v;
    }
};