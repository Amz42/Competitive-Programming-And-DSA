// Question: https://practice.geeksforgeeks.org/problems/rearrange-characters/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=3b529e465b658d9bcecb3b82a02e2735&pid=1701&user=amanguptarkg6

#include <iostream>
using namespace std;

int main() {
	int tests; cin>>tests;
	while(tests--){
	    string s; cin>>s;
	    int n = s.size(), mx = 0;
	    int f[26]={0};
	    
	    for(int i=0;i<n;i++) mx = max(++f[s[i]-'a'],mx);
	    
	    if(n&1) n++;
	    cout<<( mx>n/2 ? "0" : "1" );
	    cout<<endl;
	}
	return 0;
}