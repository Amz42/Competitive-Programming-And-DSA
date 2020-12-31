// Question: https://practice.geeksforgeeks.org/problems/set-bits0143/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=0b835d960a19460b2162edfa063f8cbb&pid=703762&user=amanguptarkg6

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


class Solution{
public:
    int setBits(int N){
        int answer = 0;
        while(N){
            if(N&1) answer++;
            N = N >> 1;
        }
        return answer;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
  // } Driver Code Ends