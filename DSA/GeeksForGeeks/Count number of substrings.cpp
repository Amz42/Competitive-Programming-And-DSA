// Question: https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=c585dfbc63046fbd5c31b260b317fb07&pid=702992&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    long long fun(string& s, int k){
        int n = s.size(), unique = 0, l = 0;
        long long answer = 0;
        int freq[26] = {0};
        
        for(int r=0;r<n;r++){
            freq[s[r]-'a']++;
            if(freq[s[r]-'a'] == 1)
                unique++;
                
            while(unique > k){
                freq[s[l]-'a']--;
                if(freq[s[l]-'a'] == 0)
                    unique--;
                l++;
            }
            
            answer += (r - l + 1);
        }
        
        return answer;
    }
public:
    long long int substrCount (string s, int k){
    	return fun(s, k) - fun(s, k-1);
    }
};

// { Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}  // } Driver Code Ends