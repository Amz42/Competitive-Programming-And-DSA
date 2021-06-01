// Question: https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=7214f41bec786013e68aa140b2b9393d&pid=702817&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n){
        int a[n];
        for(int i=0;i<n;i++) a[i] = arr[i];
        
        int p = 0;
        for(int i=0;i<n;i++)
            if(a[i]>=0) arr[p++] = a[i];
        for(int i=0;i<n;i++)
            if(a[i]<0) arr[p++] = a[i];
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends