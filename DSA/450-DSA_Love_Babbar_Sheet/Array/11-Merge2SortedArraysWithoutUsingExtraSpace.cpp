// Question: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=97b8f9e51a62842fc5f83c3a3bec8293&pid=702715&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int nextGap(int gap){return (gap/2) + (gap&1);}
    
	void merge(int a1[], int a2[], int n, int m) {
	    int gap = n+m;
	    
	    do{
	        gap = nextGap(gap);
	        int i=0;
	        while( (i+gap) < n+m ){
	            int p1,p2;
	            if(i+gap<n){ // both pointers are in 1st array
	                p1 = i, p2 = i+gap;
	                if(a1[p1]>a1[p2]) swap(a1[p1], a1[p2]);
	            }else if(i>=n){ // both pointer are in 2nd array
	                p1 = i-n, p2 = (i+gap)-n;
	                if(a2[p1]>a2[p2]) swap(a2[p1], a2[p2]);
	            }else{ // 1st pointer is in 1st & 2nd in 2nd array
	                p1 = i, p2 = (i+gap)-n;
	                if(a1[p1]>a2[p2]) swap(a1[p1], a2[p2]);
	            }
	            i++;
	        }
	    }while(gap!=1);
	}
};

int main() {
    int t; cin >> t; while (t--) {
        int n, m, i; cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) cin >> arr1[i];
        for (i = 0; i < m; i++) cin >> arr2[i];
        Solution ob; ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) cout << arr1[i] << " ";
        for (i = 0; i < m; i++) cout << arr2[i] << " ";
        cout << "\n";
    }
    return 0;
}