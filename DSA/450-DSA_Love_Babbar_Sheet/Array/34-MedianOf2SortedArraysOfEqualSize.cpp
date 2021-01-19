// Question: https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=001c24b140b8e642220081923b8f61ed&pid=703903&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	public:
		int find_median(vector<int> v){
		    sort(v.begin(), v.end());
		    return ( 
		        v.size()&1 ?
		            v[v.size()/2]
		            : (v[v.size()/2-1] + v[v.size()/2])/2
            );
		}
};

int main(){
    int T; cin >> T; while(T--){
    	int n; cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++) cin>>v[i];
    	Solution ob; int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}