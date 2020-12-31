// Question: https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=25e633022a8e19c1b59d667ebe2ca92e&pid=701158&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

// Function to count set bits in the given number x
// n: input to count the number of set bits

int countSetBits(int n){
    int b = 2;
    int num = n+1;
    int answer = 0;
    
    while(n){
        answer += ((num/b) * (b>>1));
        int md = ((num%b) - (b>>1));
        if(md>0) answer += md;
        
        n >>= 1;
        b <<= 1;
    }
    
    return answer;
}


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       
	       cout << countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends