// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
// https://practice.geeksforgeeks.org/viewSol.php?subId=3644f37ded2be583acb126152231ba79&pid=702950&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int tptr = m;
	    int row = 0;
	    for(int i=0;i<n;i++){
	        int ptr = tptr;
	        while(ptr>0 && arr[i][ptr-1]==1) ptr--;
	        if(ptr<tptr) row = i, tptr = ptr;
	    }
	    
	    if(tptr == m) return -1;
	    return row;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends