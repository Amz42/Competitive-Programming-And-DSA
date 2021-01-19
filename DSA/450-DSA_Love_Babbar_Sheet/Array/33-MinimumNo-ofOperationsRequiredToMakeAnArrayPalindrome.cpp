// Question: https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=aeb0399a1f82d3676dc13d580f881fec&pid=700419&user=amanguptarkg6

#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main(){
	int t; cin>>t; while(t--){
		int n; cin>>n; int a[n];
		for(int i = 0; i < n; i++) cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}

bool isPalindrome(int n){
    string s = to_string(n);
    int l = s.size();
    for(int i = 0;i<l/2;i++) if(s[i]!=s[l-i-1]) return false;
    return true;
}

/*Complete the function below*/
int PalinArray(int a[], int n){
    bool yes = true;
    
    for(int i=0;i<n;i++) if(!isPalindrome(a[i])){ yes = false; break;}
    
    return (yes ? 1 : 0);
}