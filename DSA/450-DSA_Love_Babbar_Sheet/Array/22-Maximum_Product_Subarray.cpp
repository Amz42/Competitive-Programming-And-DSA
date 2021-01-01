// Question: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=e9cc6291f56044223e7818b03f802771&pid=702919&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    long long int minVal = arr[0];
	    long long int maxVal = arr[0];
	    long long int answer = arr[0];
	    
	    for(int i=1;i<n;i++){
	        if(arr[i]<0) swap(maxVal,minVal);
	        
	        maxVal = max((long long int)arr[i], maxVal*arr[i]);
	        minVal = min((long long int)arr[i], minVal*arr[i]);
	        answer = max(answer, maxVal);
	    }
	    
	    return answer;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}