// Question: https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Solution: https://leetcode.com/submissions/detail/474499727/

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
    struct node{
        char c; int end;
        node* child[26];
    };
    node *newNode(char ch){
        node *n = new node;
        n->c = ch; n->end = 0;
        for(int i=0;i<26;i++) n->child[i] = NULL;
        return n;
    }
    node *root = newNode('/');
    
    // inserting data into trie
    void insert(string s){
        int index = 0, i = 0;
        node* p = root;
        while(s[i]){
            index = s[i] - 'a';
            if(p->child[index] == NULL)
                p->child[index] = newNode(s[i]);
            p = p->child[index];
            i++;
        }
        p->end += 1;
    }
    
    bool mySearch(string& s, int index, node* p){
        if(index == s.size())
            return (p->end>0);
        
        // char is '.' search for all available strings
        if(s[index] == '.'){
            for(int i=0;i<26;i++){
                if(p->child[i] != NULL && mySearch(s, index+1, p->child[i]))
                    return true;
            }
        }
        
        // search for particular char
        else if(p->child[s[index]-'a'] != NULL)
            return mySearch(s, index+1, p->child[s[index]-'a']);
        
        return false;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary(){}
    void addWord(string word) {
        insert(word);
        return;
    }
    
    bool search(string word) {
        return mySearch(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


int main(){
    return 0;
}