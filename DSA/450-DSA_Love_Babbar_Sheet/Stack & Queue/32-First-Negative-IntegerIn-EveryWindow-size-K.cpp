// Question: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=4bdceff424b37a5ae6f069edb668a791&pid=2002&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

// APPROACH: Plain Sliding Window Technique with Queue

int main() {
	int tests; cin>>tests; while(tests--){
	    int n,k; cin>>n;
	    int v[n]; for(int i=0;i<n;i++) cin>>v[i];
	    cin>>k;
	    
	    queue<int> q;
	    for(int i=0;i<k;i++) if(v[i]<0) q.push(i);
	    
	    int start = 0;
	    int finish = k-1;
	    vector<int> answer;
	    
	    while(finish != n){
	        // compute for current window
	        if(q.size()) answer.push_back(v[q.front()]);
	        else answer.push_back(0);
	        
	        // discard front of current window
	        if(v[start]<0) q.pop();
	        
	        start++, finish++;
	        
	        // add rear to new window
	        if(finish<n && v[finish]<0) q.push(finish);
	    }
	    
	    for(auto k: answer) cout << k << " ";
	    cout<<endl;
	}
	return 0;
}