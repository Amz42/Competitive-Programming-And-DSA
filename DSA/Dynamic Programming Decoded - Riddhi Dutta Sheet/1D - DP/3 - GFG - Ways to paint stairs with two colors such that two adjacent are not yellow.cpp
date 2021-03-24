// Article: https://www.geeksforgeeks.org/ways-paint-stairs-two-colors-two-adjacent-not-yellow/

// C++ Program to find the number of ways to paint stairs
#include <bits/stdc++.h>
using namespace std;

// Function to find the number of ways
int ways(int n){
	int W[n + 1];
	// take base case for 1 and 2
	W[1] = 2; W[2] = 3;
	for (int i = 3; i <= n; i++) W[i] = W[i - 1] + W[i - 2];

	return W[n];
}

int main(){
	int n = 3; cout<<ways(n);
	return 0;
}