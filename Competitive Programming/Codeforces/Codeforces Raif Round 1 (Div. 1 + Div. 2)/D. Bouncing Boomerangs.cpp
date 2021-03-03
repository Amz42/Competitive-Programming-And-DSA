// Question: https://codeforces.com/contest/1428/problem/D
// Solution: https://codeforces.com/contest/1428/submission/96308147

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define u_map       unordered_map
#define sht         short
#define pb          push_back
#define mkpr        make_pair
#define NL          cout<<"\n";
#define optimize    ios::sync_with_stdio(0);cin.tie(0);
#define fori(a,n)   for(ll int i=a;i<(ll int)n;i++)
#define forj(a,n)   for(ll int j=a;j<(ll int)n;j++)
#define MOD         1e9+7
#define ten5        1e5
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
#define LOWCASE(s)  transform(all(s),s.begin(),::tolower);
#define UPCASE(s)   transform(all(s),s.begin(),::toupper);
#define setbits(b)  __builtin_popcount(b);
#define tests       ll int t;cin>>t;while(t--)
using namespace std;
int main(){
    optimize
    /////// Write from here
    
    int n; cin>>n;
    int a[n]; fori(0,n) cin>>a[i];
    // bool mat[n+1][n+1]={0};
    vector<pair<int,int>> answer;
    
    stack<int> t2,t3;
    int row = 1;
    bool not_possible = false;
    
    
    // filling the matrix
    fori(0,n){
        int col = i+1;
        if(row>n){not_possible = true; break;}
        if(a[i]==3){ // value = 3
            if(!t3.empty()){ // 3 comes after some 3
                // mat[t3.top()][col] = 1;
                answer.pb( make_pair( t3.top(),col ) );
                t3.pop();
            }
            // mat[row][col] = 1;
            answer.pb( make_pair( row,col ) );
            // pushing row in stack
            t3.push(row);
            row++;
        }else if(a[i]==2){ // value = 2
            if(!t3.empty()){ // 2 comes after some 3
                // mat[t3.top()][col] = 1;
                answer.pb( make_pair( t3.top(),col ) );
                t3.pop();
            }
            
            // mat[row][col] = 1;
            answer.pb( make_pair( row,col ) );
            // pushing row in stack
            t2.push(row);
            row++;
        }else if(a[i]==1){ // value = 1
            if(!t2.empty()){ // 1 comes after some 2
                // mat[t2.top()][col] = 1;
                answer.pb( make_pair( t2.top(),col ) );
                t2.pop();
            }
            else if(!t3.empty()){ // 1 comes after some 3
                // mat[t3.top()][col] = 1;
                answer.pb( make_pair( t3.top(),col ) );
                // mat[row][col] = 1;
                answer.pb( make_pair( row,col ) );
                t3.pop();
                row++;
            }else{ // 1 comes alone
                // mat[row][col]=1;
                answer.pb( make_pair( row,col ) );
                row++;
            }
        }
        
        if(not_possible) break;
    }
    
    
    
    // printing the answers
    if(!t2.empty() || !t3.empty() || not_possible) cout<<-1;
    else{
        cout<<answer.size()<<endl;
        for(auto k: answer){
            cout<<k.first<<" "<<k.second<<endl;
        }
    }
    
	return 0;
}