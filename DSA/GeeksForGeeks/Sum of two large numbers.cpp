// Question: https://practice.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=0459405aadd117989a9980805b2f9fee&pid=703082&user=amanguptarkg6

 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string findSum(string x, string y){
	    reverse(x.begin(), x.end());
	    reverse(y.begin(), y.end());
	    
	    int carry = 0;
	    vector<int> v;
	    for(int i=0;i<max(x.size(), y.size());i++){
	        int data = carry + (i<x.size() ? x[i]-'0' : 0) + (i<y.size() ? y[i]-'0' : 0);
	        v.push_back(data%10);
	        carry = data/10;
	    }
	    
	    while(carry){
	        v.push_back(carry%10);
	        carry /= 10;
	    }
	    
	    string s = "";
	    for(auto k: v) s += (char)('0' + k);
	    
	    while(*s.rbegin()=='0' && s.size()>1) s.pop_back();
	    
	    reverse(s.begin(), s.end());
	    
	    return s;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string x, y;
   		cin >> x >> y;
        Solution ob;
   		cout << ob.findSum(x, y) << "\n";
   	}

    return 0;
}  // } Driver Code Ends