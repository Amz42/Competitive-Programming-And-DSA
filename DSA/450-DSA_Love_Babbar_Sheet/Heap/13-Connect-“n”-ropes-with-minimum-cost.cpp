// Question: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=3eade495027f503eab43927e85e359d9&pid=701357&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


long long minCost(long long a[], long long n) {
    priority_queue<long long> pq;
    
    for(int i=0;i<n;i++) pq.push(-a[i]);
    long long answer = 0;
    
    while(pq.size()>=2){
        long long x,y;
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        long long sum = x + y;
        answer += sum;
        pq.push(sum);
    }
    
    return (answer * -1LL);
}
