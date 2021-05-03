// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468983

#include <bits/stdc++.h>
using namespace std;

int subArrayCount(vector<int> arr, int k) {
    int n = arr.size();
    long long mod[k] = {0};
    
    long long sum = 0;
    for(int i=0;i<n;i++)
        mod[(sum = ( (sum + arr[i])%k + k)%k)]++;
    
    long long answer = 0;
    for(int i=0;i<k;i++)
        if(mod[i]>1)
            answer += (mod[i]*(mod[i]-1)/2);
    answer += mod[0];
    return answer;
}


int main(){
    return 0;
}