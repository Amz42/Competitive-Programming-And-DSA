### Binary Exponentiation with Modulo

##### C++

```c++
long long int power(long long int base,long long int _power,long long int _mod = LLONG_MAX) {
    long long int result = 1;
    base %= _mod;
    while (_power > 0) {
        if (_power & 1) result = (result * base) % _mod;
        _power = _power >> 1;
        base = (base * base) % _mod;
    }
    return result;
}
```