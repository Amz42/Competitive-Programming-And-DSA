// Question: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=81ae6044a8055bcf391c12433d727b91&pid=703336&user=amanguptarkg6

// APPROACH: By using simple sliding window technique


// C++ program to find minimum swaps required
// to club all elements less than or equals to k together
#include <iostream>
using namespace std;

int minSwap(int *arr, int n, int k);

int main() {
	int t,n,k; cin>>t; while(t--){
        cin>>n;
        int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}


int minSwap(int *arr, int n, int k) {
    int totalLessThanK = 0;
    for(int i=0;i<n;i++) if(arr[i]<=k) totalLessThanK++;
    
    int i=0,count=0;
    for(int j=0;j<totalLessThanK;j++) if(arr[j]<=k) count++;
    int answer = count;
    
    for(int j = totalLessThanK;j<n;j++,i++){
        count -= (arr[i]<=k ? 1 : 0);
        if(arr[j]<=k) count++;
        answer = max(answer, count);
    }
    
    return totalLessThanK - answer;
}