// Question: https://atcoder.jp/contests/dp/tasks/dp_i
// Solution: https://atcoder.jp/contests/dp/submissions/17433132

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define NL          cout<<"\n";
#define optimize    ios::sync_with_stdio(0);cin.tie(0);
#define fori(a,n)   for(ll int i=a;i<(ll int)n;i++)
#define forj(a,n)   for(ll int j=a;j<(ll int)n;j++)
using namespace std;

int N;
double a[3001];
double dp[3001][1501];

double fun(int index, int tails){
    if(index>=N) return 1;
    if(!(dp[index][tails]<0)) return dp[index][tails];

    double h=0,t=0;
    // heads
    h = fun(index+1, tails) * a[index];
    // tails
    if(tails) t = fun(index+1, tails-1) * abs(1-a[index]);
    dp[index][tails] = h+t;
    return dp[index][tails];
}

int main(){
    optimize
    /////// Write from here

    cin>>N;
    fori(0,N) cin>>a[i];

    // setting dp
    fori(0,3001){ forj(0,1501) dp[i][j] = -1.0; }

    cout<<fixed<<setprecision(10);
    cout<<(double)fun(0,N/2);

	return 0;
}
