// Question: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/bishu-and-soldiers/
// Solution: Submission ID: 52431156

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> v(n); for(auto &k: v) cin>>k;
	sort(v.begin(), v.end());
	
	vector<int> pref(n); pref[0] = v[0];
	for(int i=1;i<n;i++) pref[i] = pref[i-1] + v[i];

	int query; cin>>query;
	while(query-->0){
		int e; cin>>e;
		if(e>=v[n-1]) cout<<n<<" "<<pref[n-1];
		else{
			int index = upper_bound(v.begin(), v.end(), e) - v.begin();
			cout<<index<<" ";
			if(index) cout<<pref[index-1];
			else cout<<"0";
		}
		cout<<"\n";
	}
}