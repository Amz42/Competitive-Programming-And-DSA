// Question: https://practice.geeksforgeeks.org/problems/find-the-string-in-grid/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=0a141a211ea1b03c0f1d3374bb67ab6a&pid=1871&user=amanguptarkg6

#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int xdir[8]={0,-1,-1,-1,0,1,1,1};
int ydir[8]={1,1,0,-1,-1,-1,0,1};

bool find(vector<vector<char>> &mat, int x,int y, int n, int m, string str){
    for(int i=0;i<8;i++){
        int X = x + xdir[i];
        int Y = y + ydir[i];
        int j = 1;
        
        //finding string have size of 1
        if(j == str.length()) return true;
        
        while(X>=0 && Y>=0 && X<n && Y<m){
            if(mat[X][Y]==str[j]){
                j++;
                if(j==str.length()) return true;
                X += xdir[i];
                Y += ydir[i];
            }else break;
        }
    }
    
    return false;
}

void solution(vector<vector<char>> &mat, int n, int m, string str){
    int found = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(str[0]==mat[i][j] && find(mat,i,j,n,m,str)){
                cout<<i<<" "<<j<<", ";
                found = 1;
            }
        }
    }
    
    if(found == 0) cout<<"-1";
    
    cout<<"\n";
}

int main(){
    optimize
	///////////////////////////////////////////////////////////////////
	int tests; cin>>tests;
	while(tests--){
	    int n,m; cin>>n>>m;
	    
	    vector<vector<char>> mat(n,vector<char>(m));
	    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mat[i][j];
	    
	    string s; cin>>s;
	    solution(mat,n,m,s);
	}
	return 0;
}