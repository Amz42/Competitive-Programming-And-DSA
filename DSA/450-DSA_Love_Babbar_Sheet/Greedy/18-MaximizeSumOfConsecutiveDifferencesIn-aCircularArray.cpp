// Question: https://practice.geeksforgeeks.org/problems/swap-and-maximize/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=70da69785054599dc3f3f0f1dd409043&pid=2160&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests; cin>>tests; while(tests--){
	    int n; cin>>n;
	    vector<int> v(n); for(auto &k: v) cin>>k;
	    sort(v.begin(), v.end());
	    vector<int> a;
	    
	    int i = 0, l = 0, r = n-1;
	    while(l<=r){
	        if(i) a.push_back(v[l++]);
	        else  a.push_back(v[r--]);
	        i ^= 1;
	    }
	    
	    int answer = 0;
	    for(int i=1;i<n;i++) answer += abs(a[i]-a[i-1]);
	    answer += abs(a[0]-a[n-1]);
	    
	    cout<<answer<<endl;
	}
	return 0;
}