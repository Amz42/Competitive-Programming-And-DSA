// Article: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include <bits/stdc++.h>
using namespace std;

int dp[10][10];
int split[10][10];

int MCM(int p[], int i, int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    dp[i][j] = INT_MAX;

    for(int k=i;k<j;k++){
        int cost = MCM(p, i, k) + MCM(p, k+1, j) + p[i-1]*p[k]*p[j];
        if(cost < dp[i][j]){
            dp[i][j] = cost;
            split[i][j] = k;
        }
    }

    return dp[i][j];
}

string OOM(int i, int j){
    if(i==j) return "A" + to_string(i+1) + " ";
    if(i==split[i][j]) return "(" + OOM(i,i) + OOM(i+1, j) + ")";
    if(j==split[i][j]) return "(" + OOM(i,j-1) + OOM(j, j) + ")";
    return "";
}

int main(){
    int p[] = { 20, 30, 50, 10, 5};
    int matrices = 4;
    memset(dp, -1, sizeof(dp));
    cout<<"Cost: "<<MCM(p,1,matrices)<<" ";
    cout<<"Order of Multiplication: "<<OOM(0,matrices-1);
}