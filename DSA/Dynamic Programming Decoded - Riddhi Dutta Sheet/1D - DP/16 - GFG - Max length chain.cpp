// Question: https://practice.geeksforgeeks.org/problems/max-length-chain/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=3fc46eaf5c2649741f2ec8369154cf3b&pid=700342&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[], int n){
    //Your code here
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){v.push_back(make_pair(p[i].first, p[i].second));}
    sort(v.begin(),v.end());
    
    int dp[n];
    
    for(int i=0;i<n;i++){
        int x = 0;
        for(int j=0;j<i;j++){
            if(v[j].second<v[i].first)
                x = max(x,dp[j]);
        }
        dp[i] = x+1;
    }
    
    return *max_element(dp,dp+n);
}