// Question: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
// Solution: https://www.hackerearth.com/submission/55626726/

#include <iostream>
using namespace std;
 
int main(){
	int n, m; cin>>n>>m;
	int cf[n+1] = {0};
 
	while(m--){
		int x, y; cin>>x>>y;
		cf[x]++; cf[y+1]--;
	}
 
	for(int i=1;i<n+1;i++) cf[i] += cf[i-1];
	int a[n+1]={0};
	for(int i=0;i<n+1;i++) a[cf[i]]++;
	for(int i=n-1;i>=0;i--) a[i] += a[i+1];
 
	int q; cin>>q;
	while(q--){
		int x; cin>>x;
		cout<<a[x]<<endl;
	}
 
	return 0;
}