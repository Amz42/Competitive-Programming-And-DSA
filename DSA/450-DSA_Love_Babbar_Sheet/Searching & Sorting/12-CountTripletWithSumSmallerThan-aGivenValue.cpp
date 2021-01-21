// Question: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=aa52f6e36d8710f2c23d68ce6bcbaef0&pid=703292&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution{
	public:
	ll countTriplets(ll a[], int n, ll X){
	    sort(a,a+n);
	    
	    ll answer = 0;
	    
	    for(int i=0;i<n;i++){
	        int l = i+1, r = n-1;
	        while(l<r){
	            int sum = a[i] + a[l] + a[r];
	            if(sum<X){
	                answer += (r-l);
	                l++;
	            }else r--;
	        }
	    }	    
	    return answer;
	}
};

int main(){
   	int t; cin >> t; while (t--){
    	int n;
    	long long sum; cin>>n>>sum;
        long long arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob; cout << ob.countTriplets(arr, n, sum) << "\n";	     
    }
    return 0;
}