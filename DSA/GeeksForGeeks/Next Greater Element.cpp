// Question: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=c4003de3e4a9077863e256739d7bf0d1&pid=701343&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Function to return Next larger elements


vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<long long int> s; s.push(arr[n-1]);
    vector<long long> v(n); v[n-1]=-1;
    
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]) s.pop();
        v[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    
    return v;
}



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends