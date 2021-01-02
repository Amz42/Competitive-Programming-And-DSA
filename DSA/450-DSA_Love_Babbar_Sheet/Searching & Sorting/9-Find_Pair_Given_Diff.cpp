// Question: https://practice.geeksforgeeks.org/problems/find-pair-given-difference/0#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=d6d3ec07ec460a1b9800861ba12d3cb0&pid=2082&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int main(){
    int tests; cin>>tests;
    while(tests-->0){
        int n,k; cin>>n>>k;
        int a[n]; for(int i=0;i<n;i++) cin>>a[i];
        sort(a, a+n);

        bool found = false;
        for(int i=0;i<n;i++){
            int l = i+1, r = n-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(a[mid]==k+a[i]){
                    found = true;
                    break;
                }else if(a[mid]<k+a[i]) l = mid+1;
                else r = mid-1;
            }

            if(found) break;
        }

        if(found) cout<<"1";
        else cout<<"-1";
        cout<<endl;
    }
}