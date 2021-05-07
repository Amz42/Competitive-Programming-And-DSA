#include <bits/stdc++.h>
using namespace std;

long long int getHash(string key){
	long long int _hash = 0;
	long long int p = 31;           // p >= (size of char set)
	long long int p_power = 1;
    long long int _mod = 1e9+7;
 
	for(char ch : key){
		_hash = (_hash + (ch - 'a' + 1) * p_power) % _mod;
		p_power = (p_power * p) % _mod;
	}
 
	return _hash;
}

int main(){
    return 0;
}