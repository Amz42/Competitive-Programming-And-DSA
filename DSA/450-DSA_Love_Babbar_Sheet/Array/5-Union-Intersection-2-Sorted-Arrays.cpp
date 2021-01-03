// Question: https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=c2ae8580872c7c4a459e162c39b0d0bf&pid=537&user=amanguptarkg6

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	//code
	ll int tests; cin>>tests;
	while(tests-->0){
	    ll int n,m,x; cin>>n>>m;
	    ll int k = 100001;
	    bool a[100001]={0};
	    
	    for(int i=0;i<n+m;i++) cin>>x, a[x] = 1;
	    
	    cout<<(ll int)accumulate(a, a+k, 0)<<"\n";
	}
	return 0;
}