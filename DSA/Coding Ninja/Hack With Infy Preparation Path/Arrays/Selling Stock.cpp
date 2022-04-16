// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468988

#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *values, int n){
    
    long profit = 0, last = values[0];
    for(int i=0;i<n;i++){
        if(values[i]<last) last = values[i];
        else if(values[i]>last){
            profit += values[i] - last;
            last = values[i];
        }
    }
    
    return profit;
}

int main(){
    return 0;
}