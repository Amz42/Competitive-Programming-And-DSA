// Question: https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=7a149277d4c42a8db1cc8f6fba7da84a&pid=702918&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
	long long subCount(long long arr[], int n, long long k){
	    long long mod[k] = {0};
	    long long answer = 0, sum = 0;
	    
	    for(int i=0;i<n;i++)
	        mod[( sum = ((sum + arr[i])%k + k)%k )]++;
        
        for(int i=0;i<k;i++)
            if(mod[i]>1)
                answer += ((mod[i]*(mod[i]-1))/2);
        answer += mod[0];
        
        return answer;
	}
};


// { Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends