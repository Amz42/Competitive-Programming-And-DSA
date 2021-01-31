// Question: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=fafd88d3a1f29e5b6a197f786fd23024&pid=701364&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;
void maxMeetings(int *, int *, int);
int main() {
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];
        for (int i = 0; i < n; i++) cin >> end[i];

        maxMeetings(start, end, n);
        cout << endl;
    }
    return 0;
}

struct meeting{
    int start_,end_,pos_;
};

bool f(struct meeting a, struct meeting b){
    if(a.end_ == b.end_) return a.pos_ < b.pos_;
    return a.end_ < b.end_;
}

void maxMeetings(int start[], int end[], int n) {
    // Your code here
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].start_ = start[i];
        meet[i].end_ = end[i];
        meet[i].pos_ = i+1;
    }
    
    sort(meet, meet+n, f);
    
    int tim = meet[0].end_;
    
    vector<int> answer; answer.push_back(meet[0].pos_);
    
    for(int i=1;i<n;i++){
        if(meet[i].start_>tim){
            tim = meet[i].end_;
            answer.push_back(meet[i].pos_);
        }
    }
    
    for(auto k: answer) cout<<k<<" ";
}