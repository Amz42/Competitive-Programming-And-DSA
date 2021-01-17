// Question: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f2a5fa9cfbfa2066c4fcc2d3cc7cb24a&pid=705333&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string s){
		    int n = s.size();
		    queue<char> q;
		    int freq[26]={0};
		    
		    string answer = "";
		    for(int i=0;i<n;i++){
		        if(freq[s[i]-'a']==0) q.push(s[i]);
		        freq[s[i]-'a']++;
		        
		        while(!q.empty() && freq[q.front()-'a']>1) q.pop();
		        if(!q.empty()) answer += q.front();
		        else answer += "#";
		    }
		    
		    return answer;
		}

};

int main(){
	int tc; cin >> tc; while(tc--){
		string A; cin >> A;
		Solution obj; string ans = obj.FirstNonRepeating(A); cout << ans << "\n";
	}
	return 0;
}