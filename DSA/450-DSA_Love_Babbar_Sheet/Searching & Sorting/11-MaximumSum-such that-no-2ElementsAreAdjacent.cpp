// Question: https://practice.geeksforgeeks.org/problems/stickler-theif/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b7dda82668fa9ecc790ac2e501489b09&pid=701417&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

/*
APPROACH: By simple fibonacci type approach
*/

// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll a[], ll n){
    if(n==1) return a[0];
    if(n==2) return max(a[0], a[1]);
    
    ll x = a[0], y = max(a[1], a[0]), z;
    for(int i=2;i<n;i++){
        z = max(x+a[i],y);
        x = y;
        y = z;
    }    
    return z;
}

int main(){
	int t; cin>>t; while(t--){
		ll n; cin>>n;
		ll a[n]; for(ll i=0;i<n;++i) cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}