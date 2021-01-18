// Question: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=8a15fea3462b18535e10b2e4d34361f5&pid=701295&user=amanguptarkg6


#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n);
int main(){
    int  t,n,i,a[100001]; cin>>t; while(t--){
        cin>>n;
        for(i=0;i<n;i++) cin>>a[i];
        cout<<findLongestConseqSubseq(a, n)<<endl;
    }
    return 0;
}

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N){
    bool f[(int)(1e5+2)]={0};
    for(int i=0;i<N;i++) f[arr[i]] = true;
    
    int answer = 0, count = 0;
    for(int i=0;i<1e5+2;i++){
        if(f[i]) count++;
        else{
            answer = max(answer,count);
            count = 0;
        }
    }
    return answer;
}