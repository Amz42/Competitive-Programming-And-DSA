// Question: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=3bb79c627719149ce40c88fb23729822&pid=702823&user=amanguptarkg6

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int tests; cin>>tests; while(tests--){
	    int n,m; cin>>n;
	    ll int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    cin>>m;
	    sort(a,a+n);
	    
	    int i=0;
	    ll int answer = LLONG_MAX;
	    while(i+m-1<n){
	        answer = min(answer, a[i+m-1]-a[i]);
	        i++;
	    }
	    
	    cout<<answer<<"\n";
	}
	return 0;
}