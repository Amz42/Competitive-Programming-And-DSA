// Question: https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6f7a22ce53f5dbfe4710fc240b7aa4a6&pid=703185&user=amanguptarkg6

#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int> pq;
	    for(int i=0;i<n;i++){
	        pq.push(-arr[i]);
	        if(pq.size()>k) pq.pop();
	    }
	    
	    vector<int> answer;
	    while(!pq.empty()){
	        answer.push_back(-pq.top());
	        pq.pop();
	    }
	    reverse(answer.begin(), answer.end());
	    
	    return answer;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends