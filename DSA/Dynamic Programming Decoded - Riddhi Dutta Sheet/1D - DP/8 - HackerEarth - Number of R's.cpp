// Question: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/number-of-rs-1/
// Solution: https://www.hackerearth.com/submission/55627600/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin>>t; while(t-->0){
		string s; cin>>s;
		int Rs = 0;
		for(auto k: s) Rs += (k=='R');
 
		int kdn = INT_MIN, sum = 0;
		for(int k=0;k<s.size();k++){
			int g = (s[k] == 'R' ? -1 : +1);
			sum = max({sum+g, g});
			kdn = max(kdn, sum);
		}
 
		cout << kdn + Rs << endl;
	}
}