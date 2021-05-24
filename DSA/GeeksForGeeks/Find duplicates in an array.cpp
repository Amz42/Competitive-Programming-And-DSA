// Question: https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=16da288c3978b2a1954addd5e84c7476&pid=700437&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        for(int i=0;i<n;i++){
            int e = arr[i] % n;
            arr[e] += n;
        }
        
        vector<int> answer;
        for(int i=0;i<n;i++){
            if(arr[i]/n > 1)
                answer.push_back(i);
        }
        
        if(answer.size() == 0)
            answer.push_back(-1);
        
        return answer;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends