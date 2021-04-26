// Question: https://codeforces.com/contest/1389/problem/C
// Solution: https://codeforces.com/contest/1389/submission/88400194

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int test; cin>>test;
    while(test--){
        string str; cin>>str;
        int ans=0;
        for(char a='0';a<='9';a++){
            for(char b='0';b<='9';b++){
                bool c=0,d=0;
                int cnt1,cnt2; cnt1=cnt2=0;
                for(auto k: str){
                    if((c && k==a)||(!c && k==b)){c=!c;cnt1++;}
                    if((d && k==b)||(!d && k==a)){d=!d;cnt2++;}
                }
                if(cnt1&1 && a!=b)cnt1--;
                if(cnt2&1 && a!=b)cnt2--;
                ans=max(ans,max(cnt1,cnt2));
            }
        }
        cout<<str.size()-ans<<endl;
    }
	return 0;
}