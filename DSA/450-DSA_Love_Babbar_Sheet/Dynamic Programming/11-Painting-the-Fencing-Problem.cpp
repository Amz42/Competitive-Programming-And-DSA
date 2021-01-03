// Question: https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=02fb867f252cd32f14a9878bde5a4b87&pid=702814&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long countWays(int n, int k){
        const long long int MOD = 1e9+7;
        
        // x = all possibilities of last of last post
        // y = all possibilities of last post
        
        long long int x = k , y = k*k;
        if(n==1) return x;
        if(n==2) return y;
        
        long long int answer;
        for(int i=3;i<=n;i++){
            // answer = (k-1) * x + (k-1) * y; // this is reduced down to below
            answer = ( (k-1) * ((x + y) % MOD) ) % MOD;
            x = y;      //  new last of last
            y = answer; //  new last
        }
        
        return answer;
    }
};

// APPROACH:
// 1. For 1st post their are k choices
// 2. For 2nd post their are k*k choices
//   (for each color from 1st post we have k choices so 'k' from 1st * 'k' for current = k*k)
// 3. For n-th post:
//      if we want to color it different from last post then:
//          all possibility of last * 'k-1' for current
//      else we want to color it same as last post then:
//          current post will be different from all possibility last of last post
//          i.e. all possibility of last[last] * 'k-1'

int main(){
	int t; cin>>t; while(t--){
		int n,k; cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}