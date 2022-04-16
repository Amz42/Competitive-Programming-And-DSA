// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468994

#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
////////////////        Solution - 1
/////////////////////////////////////////////////////////////////////////////
vector<int> majorityElementII(vector<int> &arr){
    int n = arr.size();
    int freq[(int)(1e5+1)] = {0};
    
    vector<int> answer;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
        if(freq[arr[i]]>n/3){
            freq[arr[i]] = -n;
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}
/////////////////////////////////////////////////////////////////////////////
////////////////        Solution - 1
/////////////////////////////////////////////////////////////////////////////

int main(){
    return 0;
}