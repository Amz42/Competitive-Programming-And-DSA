// Question: https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1/#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=fd18ceacc7f0a316775bb5e9e08ca1f7&pid=706286&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution{
    public:
    string rearrangeString(string str){
        int freq[26] = {0};
        for(auto k: str) freq[k-'a']++;
        
        priority_queue<pair<int,char>, vector<pair<int,char>>> q;
        for(int i=0;i<26;i++)
            if(freq[i]>0)
                q.push({freq[i], (char)('a'+i)});
        
        string answer = "";
        while(q.size()>1){
            auto x = q.top(); q.pop();
            auto y = q.top(); q.pop();
            
            answer = answer + x.second + y.second;
            x.first--; y.first--;
            if(x.first>0) q.push(x);
            if(y.first>0) q.push(y);
        }
        
        if(q.size()){
            if(q.top().first>1) return "-1";
            auto x = q.top(); q.pop();
            x.first--;
            answer += x.second;
        }
        
        return answer;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends