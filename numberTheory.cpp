#include <bits/stdc++.h>
using namespace std;

//first compute sieve of erasthotenes
ll _sieve_size;
bitset<10000010> bs; //10^7 should be enough for most cases;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    
    for(ll i = 2; i <= _sieve_size; ++i) if(bs[i]) {
        //cross out multiples of i starting from i * i!
        for(ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
    }
}

bool isPrime(ll n) {
    if(N <= _sieve_size) return bs[N];
    for(int i = 0; i < (int)primes.size(); ++i) {
        if(N % primes[i] == 0) return false;
    }
    return true; // only works if N <= (last prime in primes) ^ 2
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

vi primeFactors(ll N) {
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx]; // primes populated by sieve
    while(PF * PF <= N) { //remember -> sqrt(N) only, not n
        while(N % PF == 0) { N /= PF; factors.push_back(PF); }
        PF = primes[++PF_idx];
    }
    if(N != 1) factors.push_back(N); //special case -> n is prime
    return factors;
}

int main() {
    sieve(10000000);
    printf("%d\n", isPrime(23123213));
    printf("%d\n", isPrime(1231323232213212));
    
    vi r primeFactors(231232);
    for(vi::iterator it = r.begin(); it != r.end(); ++it) {
        printf("%d\n", *i);
    }
}
