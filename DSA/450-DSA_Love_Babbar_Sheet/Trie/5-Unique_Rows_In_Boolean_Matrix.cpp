// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1
// https://practice.geeksforgeeks.org/viewSol.php?subId=b9d202722b555c0ba39ba27426b977c7&pid=700280&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

struct TrieNode{
    TrieNode* child[2];
    bool eow;
};

TrieNode* getNode(){
    TrieNode* ptr = new TrieNode;
    ptr->child[0] = ptr->child[1] = NULL;
    ptr->eow = false;
    return ptr;
}


void make_trie(TrieNode* root, vector<int> a, vector<vector<int>> &answer){
    TrieNode* ptr = root;
    
    for(int i=0;i<a.size();i++){
        int index = a[i];
        if(ptr->child[index] == NULL) ptr->child[index] = getNode();
        ptr = ptr->child[index];
    }
    
    if(ptr->eow == false) answer.push_back(a);
    ptr->eow = true;
    return;
}


// void make_answer(TrieNode* ptr, vector<int> &v){
//     if(ptr->eow){
//         answer.push_back(v);
//         return;
//     }
    
//     for(int i=0;i<2;i++){
//         if(ptr->child[i] != NULL){
//             v.push_back(i);
//             make_answer(ptr->child[i], v);
//             v.pop_back();
//         }
//     }
//     return;
// }

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col){
    TrieNode* root = getNode();
    
    vector<vector<int>> answer;
    
    for(int i=0;i<row;i++){
        vector<int> arr;
        for(int j=0;j<col;j++) arr.push_back(M[i][j]);
        make_trie(root, arr, answer);
    }
    
    free(root);
    
    return answer;
}