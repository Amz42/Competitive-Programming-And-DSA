// Question: https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=41967240da8cb66963f1768576eaba6b&pid=1686&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

bool isMirror(int n, vector<int> treeA[], vector<int> treeB[]){
    for(int i=1;i<=n;i++){
        int A = treeA[i].size();
        int B = treeB[i].size();
        
        if(A != B) return false;
        
        reverse(treeA[i].begin(), treeA[i].end());
        if(treeA[i] != treeB[i]) return false;
    }
    
    return true;
}

int main() {
	int tests; cin>>tests;
	while(tests--){
	    int n, e, x, y; cin >> n >> e;
	    
	    vector<int> treeA[n+1];
	    vector<int> treeB[n+1];
	    
	    for(int i=0;i<e;i++) cin>>x>>y, treeA[x].push_back(y);
	    for(int i=0;i<e;i++) cin>>x>>y, treeB[x].push_back(y);
	    
	    cout << isMirror(n, treeA, treeB) << endl;
	}
	return 0;
}