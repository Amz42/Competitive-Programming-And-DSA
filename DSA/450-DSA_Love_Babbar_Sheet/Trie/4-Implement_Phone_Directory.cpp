// https://practice.geeksforgeeks.org/problems/phone-directory/0
// https://practice.geeksforgeeks.org/viewSol.php?subId=91dba40382963870d40ad227e018ade9&pid=2463&user=amanguptarkg6

#define ll long long
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    bool endword;
};

TrieNode* getNode(){
    TrieNode* Node = new TrieNode;
    for(int i=0;i<26;i++) Node->child[i] = NULL;
    Node->endword = false;
    return Node;
}

vector<string> answer;

void search(TrieNode* ptr, string word){
    if(ptr->endword) answer.push_back(word);
    
    for(int i=0;i<26;i++){
        if(ptr->child[i] != NULL){
            search(ptr->child[i], word+(char)(i+'a'));
        }
    }
    return;
}

void makeword(TrieNode* ptr, string s){
    for(int i=0;i<s.size();i++){
        int index = s[i]-'a';
        if(ptr->child[index] == NULL) ptr->child[index] = getNode();
        ptr = ptr->child[index];
    }
    
    ptr->endword = true;
    return;
}

int main(){
	int tests; cin>>tests;
	while(tests-->0){
	    int n; cin>>n;
	    string x;
	    
	    TrieNode* root = getNode();
	    
	    for(int i=0;i<n;i++) cin>>x, makeword(root, x);
	    
	    cin>>x;
	    string k;
	    for(int i=0;i<x.size();i++){
	        k = x.substr(0, i+1);
	        
	        answer.clear();
	        
	        // apply search now
	        TrieNode* ptr = root;
	        bool prefix_match = true;
	        for(int j=0;j<k.size();j++){
	            int index = x[j] - 'a';
	            if(ptr->child[index] == NULL){
	                prefix_match = false;
	                break;
	            }
	            ptr = ptr->child[index];
	        }
	        
	        if(prefix_match){
	            search(ptr,k);
	            for(auto g: answer) cout<<g<<" ";
	        }else cout<<"0";
	        cout<<endl;
	    }
	}
	
	
	return 0;
}