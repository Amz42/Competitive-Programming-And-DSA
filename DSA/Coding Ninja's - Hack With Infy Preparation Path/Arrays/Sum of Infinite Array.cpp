// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468980

#include <bits/stdc++.h>
using namespace std;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    const int MOD = 1e9+7;
    long long total = 0;
    long long pref[n] = {0};
    
    for(int i=0;i<n;i++){
        total = (total + arr[i]%MOD) % MOD;
    	pref[i] = ((i>0 ? pref[i-1] : 0) + arr[i]) % MOD;
	}
    
    vector<int> answer;
    for(int i=0;i<q;i++){
        long long l = queries[i][0]-1;
        long long r = queries[i][1]-1;
        long long ans = (pref[r%n] - pref[l%n] + arr[l%n] % MOD + MOD) % MOD;
        
        ans += (((r/n - l/n)%MOD) * total + MOD)%MOD;
        
        answer.push_back((ans+MOD)%MOD);
    }
    
    return answer;
}

int main(){
    return 0;
}