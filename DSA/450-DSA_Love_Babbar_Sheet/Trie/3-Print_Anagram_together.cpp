// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends


//User function Template for C++
struct TrieNode{
    TrieNode* children[26];
    int index;
};

TrieNode* GetNode(){
	TrieNode* Node = new TrieNode;
	for(int i = 0 ; i < 26 ; i++)
	Node->children[i] = NULL;
	Node->index = -1;
	return Node;
}

void Search(TrieNode* root , string &ana , vector<vector<string>> &ans , string &curr){
    for(int i = 0 ; i < ana.length() ; i++){   
    	int index = ana[i] - 'a';
        if(!root->children[index])  root->children[index] = GetNode();
        root = root->children[index];
    }
    
    if(root->index == -1){
        root->index = ans.size();
        ans.push_back(vector<string>());
    }
    ans[root->index].push_back(curr);
}


vector<vector<string> > Anagrams(vector<string>& string_list) {
    vector<vector<string>> ans;
    TrieNode* root = GetNode();

    for(auto i : string_list){
        int alpha[26]={0};
        
        for(int j = 0 ; j < i.length() ; j++)
        alpha[i[j]-'a']++;
        
        string ana;
        
        for(int j = 0 ; j < 26 ; j++)
        while(alpha[j]--)
        ana.push_back((char)(j+'a'));
        
        Search(root , ana , ans , i);
    }
    
    return ans;
}







// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends