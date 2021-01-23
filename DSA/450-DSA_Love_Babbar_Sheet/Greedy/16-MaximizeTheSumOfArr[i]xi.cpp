// Question: https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=29865df8d1a416623ba504328ac4dc4d&pid=702670&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int Maximize(int a[],int n);

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n]; for(int i=0;i<n;i++) cin>>a[i];
        cout<<Maximize(a,n)<<endl;
    }
}

int Maximize(int a[],int n){
    sort(a, a+n);
    const int MOD = 1e9+7;
    long long int answer = 0;
    for(long long int i=0;i<n;i++) answer = ((i*(a[i]%MOD))%MOD + answer)%MOD;
    return answer;
}