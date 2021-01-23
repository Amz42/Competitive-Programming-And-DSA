// Question: https://practice.geeksforgeeks.org/problems/shop-in-candy-store/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=bcefbcef4b223ec2ab8d2171cafccbf6&pid=873&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests; cin>>tests; while(tests--){
	    int n,k; cin>>n>>k;
	    
	    vector<int> v(n); for(auto &i: v) cin>>i;
	    sort(v.begin(), v.end());
	    
	    int mini = 0 ,maxi = 0;
	    int p1=0,p2=n;
	    
	    while(p1<p2){
	        mini += v[p1++];
	        p2 -= k;
	    }
	    
	    p1 = n-1, p2 = -1;
	    while(p2<p1){
	        maxi += v[p1--];
	        p2 += k;
	    }
	    
	    cout << mini << " " << maxi << "\n";
	}
	return 0;
}