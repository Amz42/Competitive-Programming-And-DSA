// Question: https://www.hackerearth.com/problem/algorithm/utkarsh-and-jumps/
// Solution: https://www.hackerearth.com/submission/55588537/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
	int n; double p; cin>>n>>p;
	double dp[n+1]={0}; dp[0] = 1;
 
	for(int i=1;i<n+1;i++){
		if(i-2>=0) dp[i] += (p/100) * dp[i-2];
		if(i-3>=0) dp[i] += (1 - p/100) * dp[i-3];
	}
	cout<<fixed<<setprecision(6);
	cout<<dp[n];
 
	return 0;
}