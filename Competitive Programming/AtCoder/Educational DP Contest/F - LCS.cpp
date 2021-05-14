// Question: https://atcoder.jp/contests/dp/tasks/dp_f
// Solution: https://atcoder.jp/contests/dp/submissions/17410859

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

int mat[3001][3001];

int main(){
    optimize
    /////// Write from here
    
    string s,t; cin>>s>>t;
    int x,y,ans=0; x=y=INT_MAX;
    
    fori(1, s.size()+1){
        forj(1, t.size()+1){
            if(s[i-1]==t[j-1])  mat[i][j] = 1+mat[i-1][j-1];
            else                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            
            if(mat[i][j]>ans) ans = mat[i][j], x=i, y=j;
        }
    }
    
    if(ans==0){
        cout<<"";
    }else{
        string answer = "";
        
        while(x>0 && y>0){
            if(s[x-1]==t[y-1]){
                answer = s[x-1]+answer;
                x--, y--;
            }else if(mat[x-1][y]>mat[x][y-1]) x--;
            else y--;
        }
        
        cout<<answer;
    }
    
	return 0;
}