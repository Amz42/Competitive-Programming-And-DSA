// Article: https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// Question: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=5fc79dadedbf8bf522058d7283818b59&pid=705175&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int calc(int LT, int LF, int RT, int RF, char c, bool isTrue){
        if(c=='&'){
            if(isTrue)  return (LT * RT);
            else        return (LT * RF + LF * RT + LF * RF);
        }else if(c=='|'){
            if(isTrue)  return (LT * RF + LF * RT + LT * RT);
            else        return (LF * RF);
        }else if(c=='^'){
            if(isTrue)  return (LT * RF + LF * RT);
            else        return (LF * RF + LT * RT);
        }
    }
public:
    int countWays(int N, string S){
        int dp[N][N][2];
        memset(dp, 0, sizeof(dp));

        // marking individual 'T's & 'F's        
        for(int i=0;i<N;i+=2) dp[i][i][S[i]=='T'] = 1;
        
        // length of segment to be operated
        for(int segment=3; segment<=N; segment += 2){
            // start point of segment
            for(int i=0; i+segment-1<N ; i+=2){
                int T,F; T = F = 0;
                int j = i+segment-1;
                
                // operating on operators
                for(int k=i+1; k<j ;k+=2){
                    
                    int LT = dp[i][k-1][true];      // LEFT-TRUE
                    int LF = dp[i][k-1][false];     // LEFT-FALSE
                    int RT = dp[k+1][j][true];      // RIGHT-TRUE
                    int RF = dp[k+1][j][false];     // RIGHT-FALSE
                    
                    T += calc(LT, LF, RT, RF, S[k], true);
                    F += calc(LT, LF, RT, RF, S[k], false);
                    T %= 1003;
                    F %= 1003;
                }
                
                dp[i][j][true] = T;
                dp[i][j][false] = F;
            }
        }
        
        return dp[0][N-1][true];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends