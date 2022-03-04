## SIEVE OF ERATOSTHENES

### C++
```c++
// Time Complexity: O(n log(logn))
// Space Complexity: O(n)

const int sieve_N = 1e5;
bool is_prime[sieve_N+1];

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    
    for(int i=2; i*i<=sieve_N; i++) {
        if(is_prime[i]) {
            for(int j=i*i; j<=sieve_N; j+=i) {
                is_prime[j]=0;
            }
        }
    }
}
```