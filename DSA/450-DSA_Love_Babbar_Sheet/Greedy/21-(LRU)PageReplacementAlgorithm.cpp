// Question: https://practice.geeksforgeeks.org/problems/page-faults-in-lru/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=bf96e769fb8144dc8546d4a639c758e7&pid=2104&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests; cin>>tests;
	while(tests--){
	    int n; cin>>n;
	    int v[n]; for(int i=0;i<n;i++) cin>>v[i];
	    int capacity; cin>>capacity;
	    
	    list<int> li;
	    unordered_map<int,list<int>::iterator> mp;
	    
	    int page_faults = 0;
	    
	    for(int i=0;i<n;i++){
	        if( mp.find(v[i]) == mp.end() ){            // page fault
	            page_faults++;
	            
	            // remove least recently used page
	            if(li.size() == capacity){
	                mp.erase(li.front());
	                li.pop_front();
	            }
	            
	            li.push_back(v[i]);
	            mp[v[i]] = --li.end();
	        }else{                                      // no page fault
	            // remove page from list
	            li.erase(mp[v[i]]);
	            // update page's last used time
	            li.push_back(v[i]); 
	            mp[v[i]] = --li.end();
	        }
	    }
	    
	    cout<<page_faults<<endl;
	}
	
	return 0;
}