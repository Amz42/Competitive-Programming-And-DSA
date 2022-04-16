// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468990

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &a, int n) {
    sort(a.begin(), a.end());
    
    int answer = 1;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]) continue;
        if(a[i-1] == a[i]-1) cnt++;
        else answer = max(answer, cnt), cnt = 1;
    }
    
    answer = max(answer, cnt);
    
    return answer;
}

int main(){
    return 0;
}