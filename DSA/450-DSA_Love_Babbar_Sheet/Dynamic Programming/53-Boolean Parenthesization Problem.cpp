// Question: https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
// (Recursive) Solution1: https://practice.geeksforgeeks.org/viewSol.php?subId=3d987c0708d4c45c3bdf1d187d3c8e6c&pid=705175&user=amanguptarkg6
// (Iterative) Solution2: https://practice.geeksforgeeks.org/viewSol.php?subId=5fc79dadedbf8bf522058d7283818b59&pid=705175&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/////////                   RECURSIVE APPROACH
/////////////////////////////////////////////////////////////////////////////////////////////
class Solution{
    int dp[201][201][2];
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
    int fun(string& s, int i, int j, bool isTrue){
        if(i==j){
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        
        long long int answer = 0;
        for(int k=i+1;k<j;k+=2){
            int LT = fun(s, i, k-1, true);      // LEFT-TRUE
            int LF = fun(s, i, k-1, false);     // LEFT-FALSE
            int RT = fun(s, k+1, j, true);      // RIGHT-TRUE
            int RF = fun(s, k+1, j, false);     // RIGHT-FALSE
            
            answer += calc(LT, LF, RT, RF, s[k], isTrue);
            answer %= 1003;
        }
        
        return dp[i][j][isTrue] = answer;
    }
public:
    int countWays(int N, string S){
        memset(dp, -1, sizeof(dp));
        return fun(S, 0, N-1, true);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
/////////                   ITERATIVE APPROACH
/////////////////////////////////////////////////////////////////////////////////////////////
class Solution2{
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
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



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