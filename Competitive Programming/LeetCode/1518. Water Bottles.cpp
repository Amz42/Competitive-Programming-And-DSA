// Question: https://leetcode.com/problems/water-bottles/
// Solution: https://leetcode.com/submissions/detail/418910964/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = 0, rem=0;
        while(numBottles>0){
            answer += numBottles;
            numBottles += rem;
            rem = numBottles % numExchange;
            numBottles/=numExchange;
        }
        
        return answer;
    }
};

int main(){
    return 0;
}