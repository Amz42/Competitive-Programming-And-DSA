// Question: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=7561a5ce5a6420ca5495aa230afe350a&pid=1943&user=amanguptarkg6

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	//code
	ll int tests; cin>>tests;
	while(tests-->0){
	    ll int n; cin>>n;
	    ll int a[n]; for(int i=0;i<n;i++) cin>>a[i];
	    
	    if(n==1){
	        cout<<a[0];
	        cout<<endl;
	        continue;
	    }
	    
	    ll int ptr = 1;
	    while(ptr<n){
	        swap(a[0], a[ptr]);
	        ptr++;
	    }
	    
	    for(auto k: a) cout<<k<<" ";
	    cout<<endl;
	}
	return 0;
}