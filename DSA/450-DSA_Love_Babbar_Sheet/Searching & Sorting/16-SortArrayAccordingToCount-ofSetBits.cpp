// Question: https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=d5cf9376196f82055b05df42f51b8ad3&pid=702718&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool comp(int a, int b){
        return __builtin_popcount(a) > __builtin_popcount(b);
    }
    
    void sortBySetBitCount(int arr[], int n){
        stable_sort(arr, arr+n, comp);
    }
};

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob; ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}