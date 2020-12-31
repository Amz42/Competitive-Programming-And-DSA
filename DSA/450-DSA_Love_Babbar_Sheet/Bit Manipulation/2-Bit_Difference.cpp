// Question: https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=ba61421f7f9970bf52b5a653209a01f7&pid=701160&user=amanguptarkg6

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b){
    int answer = 0;
    
    while(a || b){
        int x = a&1;
        int y = b&1;
        
        if(x!=y) answer++;
        a >>= 1;
        b >>= 1;
    }
    
    return answer;
}

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends