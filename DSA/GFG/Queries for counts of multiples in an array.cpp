// Question: https://practice.geeksforgeeks.org/problems/queries-for-counts-of-multiples-in-an-array4028/0/
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=91158a9b9ad0c0dbf3309f53ae86e4db&pid=703821&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

vector<int> countMultiples(int arr[], int q[], int n, int m) ;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n >> m;
        int q[m], arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (i = 0; i < m; i++) cin >> q[i];

        vector<int> answering = countMultiples(arr, q, n, m);
        for (auto it : answering) cout << it << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends



vector<int> countMultiples(int A[], int Q[], int n, int m) {
    int mp[100001] = {0};
    int freq[100001] = {0};
    int mx = INT_MIN;
    for(int i=0;i<n;i++) freq[A[i]]++, mx = max(mx, A[i]);
    
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i)
            mp[i] += freq[j];
    }
    
    vector<int> answer;
    
    for(int g=0;g<m;g++)
        answer.push_back(mp[Q[g]]);
    
    return answer;
}