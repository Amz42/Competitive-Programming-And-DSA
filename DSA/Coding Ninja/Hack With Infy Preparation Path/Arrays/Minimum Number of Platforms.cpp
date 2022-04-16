// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468993

#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n){
    int ai = 0, di = 0, platforms = 0, answer = 0;
    sort(at,at+n); sort(dt,dt+n);
    
    while(ai<n){
        while(dt[di]<at[ai]) di++, platforms--;
        platforms++, ai++;
        answer = max(answer, platforms);
    }
    
    return answer;
}

int main(){
    return 0;
}