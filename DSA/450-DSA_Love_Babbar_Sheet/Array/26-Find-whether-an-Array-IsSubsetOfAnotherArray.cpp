// Question: https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=48ddb31ddd0740903cd670b9cd93c2db&pid=1994&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests; cin>>tests; while(tests-->0){
	    int n,m,x; cin>>n>>m;
	    int freq[(int)(1e5+1)]={0};
	    
	    bool yes = true;
	    for(int i=0;i<n;i++) cin>>x, freq[x]++;
	    for(int i=0;i<m;i++){
	        cin>>x;
	        if(freq[x]) freq[x]--;
	        else yes = false;
	    }
	    
	    cout<<(yes ? "Yes" : "No") << "\n";
	}
	return 0;
}