// Question: https://practice.geeksforgeeks.org/problems/find-the-string-in-grid/0
// Solution1: https://practice.geeksforgeeks.org/viewSol.php?subId=0a141a211ea1b03c0f1d3374bb67ab6a&pid=1871&user=amanguptarkg6
// Solution2: https://practice.geeksforgeeks.org/viewSol.php?subId=0f9acf5a623168ac2c26becc878e52c1&pid=705651&user=amanguptarkg6

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

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////    Solution 2
/////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    int dir[8][2] = {
        { -1, -1}, // up-left
        { -1,  0}, // up
        { -1, +1}, // up-right
        {  0, +1}, // right
        { +1, +1}, // down-right
        { +1,  0}, // down
        { +1, -1}, //down-left
        {  0, -1} // left
    };
    bool valid(int i, int j, int n, int m){
        return !(i<0 || j<0 || i>=n || j>=m);
    }
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> answer;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            
	            for(int k=0;k<8;k++){ // selecting a particular direction
	                int x = i, y = j, p = 0;
	                bool found = true;
	                while(true){
	                    if(p==word.size()) break;
	                    if(!valid(x,y,n,m) || word[p] != grid[x][y]){
	                        found = false;
	                        break;
	                    }
	                    p++;
	                    x += dir[k][0];
	                    y += dir[k][1];
	                }
	                
	                if(found){
	                    answer.push_back({i, j});
	                    break;
	                }
	            }
	            
	        }
	    }
	    
	    return answer;
	}
};
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////    Solution 2
/////////////////////////////////////////////////////////////////////////////////////////