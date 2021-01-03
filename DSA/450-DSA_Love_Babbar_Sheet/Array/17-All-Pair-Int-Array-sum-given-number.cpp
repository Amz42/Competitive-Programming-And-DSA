// Question: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f67b7471cee053c572c954c9efcf84ea&pid=703284&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

//User function template for C++
vector<int> freq;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        freq.assign(1e6+1, 0); // initializing freq array with 0
        
        int answer = 0;
        for(int i=0;i<n;i++){
            int num = arr[i];
            answer += (k-num < 1e6+1 && k-num >= 0 ? freq[k-num] : 0);
            freq[num]++;
        }
        
        return answer;
    }
};

// APPROACH:
// 1.Make a frequency array
// 2.For each value check if its corresponding value (i.e. k-value) is valid
// 3.If valid, then add its freq (i.e. freq[k-num]) in answer

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
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}