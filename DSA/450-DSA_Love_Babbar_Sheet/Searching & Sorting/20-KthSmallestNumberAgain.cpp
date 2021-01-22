// Question: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/
// Solution: Submission ID: 52433358

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int tests; cin>>tests;
	while(tests-->0){
		int n,q; cin>>n>>q;
		vector<pair<ll int, ll int>> v(n);
		for(auto &k: v) cin>>k.first>>k.second;
		sort(v.begin(), v.end());

		vector<pair<ll int, ll int>> a;
		int i=0;
		while(i<n){
			ll int start = v[i].first;
			ll int finish = v[i].second;
			while(i+1<n && finish>=v[i+1].first-1){
				finish = max(finish, v[i+1].second);
				i++;
			}

			a.push_back({start, finish});
			i++;
		}
		
		int an = a.size();
		vector<ll int> pref(an); pref[0] = a[0].second - a[0].first + 1;
		for(int i=1;i<an;i++)
			pref[i] = pref[i-1] + a[i].second - a[i].first + 1;

		while(q-->0){
			ll int k; cin>>k;
			if(k>pref[an-1]){
				cout<<"-1\n";
				continue;
			}
			int index = lower_bound(pref.begin(), pref.end(), k) - pref.begin();
			ll int ans = a[index].first + (index ? k-pref[index-1] : k ) - 1;
			cout<<ans<<"\n";
		}
	}
}