// Question: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a023a1998e31cdfc61aea43a4a8dc148&pid=355&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int multiply(vector<int> &fact, int num, int digits){
    int carry = 0;
    
    for(int i=0;i<digits;i++){
        int result = fact[i] * num + carry;
        fact[i] = result%10;
        carry = result/10;
    }
    
    while(carry){
        fact[digits] = carry%10;
        carry /= 10;
        digits++;
    }
    
    return digits;
}

int factorial(vector<int> &fact, int n){
    fact[0] = 1;
    int digits = 1;
    for(int i=2;i<=n;i++){
        digits = multiply(fact, i, digits);
    }
    
    return digits;
}

int main() {
	int tests; cin>>tests;
	while(tests-->0){
	    int n; cin>>n;
	    vector<int> fact(5000,0);
	    int digits = factorial(fact,n);
	    for(int i=digits-1;i>=0;i--) cout<<fact[i];
	    cout<<endl;
	}
	return 0;
}