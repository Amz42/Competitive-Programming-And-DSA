// Question: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=995a89ad95af4b11ee473d727e75d7de&pid=700380&user=amanguptarkg6

// Counts Palindromic Subsequence in a given String
#include<iostream>
#include<cstring>
using namespace std;
 
// Function return the total palindromic subsequence
int countPS(string str);
 
// Driver program
int main()
{
   int t;
	cin>>t;
   while(t--)
	{
	string str;
cin>>str;
cout<<countPS(str)<<endl;
} 
}// } Driver Code Ends

int dp[1001][1001];
string s;

int fun(int i, int j){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    
    int answer = 0;
    if(s[i]==s[j]) answer = fun(i+1,j) + fun(i,j-1) + 1;
    else answer = fun(i+1,j) + fun(i,j-1) - fun(i+1,j-1);
    
    return dp[i][j] = answer;
}

int countPS(string str){
   memset(dp, -1, sizeof(dp));
   s = str;
   return fun(0,str.size()-1);
}

// APPROACH:
// 1. if first & last character are equal then:
//      answer = cps(first+1,last) + cps(first,last-1) + 1(for first & last to be equal)
// 2. first & last character not equal:
//      answer = cps(first+1,last) + cps(first,last-1) - cps(i+1, j-1)