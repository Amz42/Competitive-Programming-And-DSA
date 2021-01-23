// Question: https://practice.geeksforgeeks.org/problems/minimum-platforms/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=665f3bb3a4cc388299aa7627ec3cbb16&pid=701368&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n){
	sort(arr, arr+n);
	sort(dep, dep+n);
	
	int aptr = 0, dptr = 0, current_platforms = 0, answer = 0;
	while(aptr<n){
	    if(dep[dptr]<arr[aptr]) dptr++, current_platforms--;
	    else aptr++, current_platforms++;
	    
	    answer = max(answer, current_platforms);
	}
	
	return answer;
}

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        int arr[n], dep[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int j=0;j<n;j++) cin>>dep[j];
        cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}