// Question: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
// Soltuion: https://practice.geeksforgeeks.org/viewSol.php?subId=e661a3fc8055f3f89175a75822af8220&pid=701170&user=amanguptarkg6

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

// Function to check power of two
bool isPowerofTwo(long long n){
    while(n){
        if(n&1){
            n >>= 1;
            break;
        }
        n >>= 1;
    }
    
    return (n==0);
}

// { Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;
        if(n<=0) // if n is less than equal to zero then it can't be a power of 2
        {
            cout<<"NO"<<endl; //so we print No
            continue; //continue and check for other values
        }

         if(isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}
  // } Driver Code Ends