// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468981

#include <bits/stdc++.h>
using namespace std;

vector<int> xorQuery(vector<vector<int>>& Q){
	int n = Q.size();
    vector<int> answer;
    int XR = 0;
    
    for(auto k: Q)
        if(k[0]==2)
            XR ^= k[1];
    
    for(auto k: Q){
        if(k[0]==2) XR ^= k[1];
        else answer.push_back(k[1]^XR);
    }
    
    return answer;
}

int main(){
    return 0;
}