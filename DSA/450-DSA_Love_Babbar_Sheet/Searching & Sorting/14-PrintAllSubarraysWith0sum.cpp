// Question: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=db62915f23a4e8bdb5fdccdbbcbbf005&pid=701741&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll findSubarray(vector<ll> , int );

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<ll> arr(n,0); for(int i=0;i<n;i++) cin>>arr[i];
        cout << findSubarray(arr,n) << "\n";
    }
	return 0;
}

ll findSubarray(vector<ll> arr, int n){
    unordered_map<ll,ll> mp; mp[0] = 1;
    
    ll answer = 0, sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(mp[sum]) answer += mp[sum];
        mp[sum]++;
    }
    
    return answer;
}