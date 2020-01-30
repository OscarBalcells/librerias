#include <bits/stdc++.h>
using namespace std;

const ll mod = 1e9L + 7;
const int nax = 2e5 + 7;

//computamos los factoriales y la inversa de ellos
ll fact[nax], rfact[nax];
//con estos podemos calcular facilmente los coeficientes binomiales

ll power(ll x, ll y) {
    if(y == 0) {
        return 1;
    } else if(y % 2 == 1) {
        return power(x, y-1) * x % mod;
    } else {
        ll tmp = power(x, y / 2);
        return tmp * tmp % mod;
    }
}

ll binomCoeff(int a, int b) {
    return fact[a] * (fact[b] * fact[a - b] % mod) % mod;
}

int main() {
    
    fact[0] = rfact[0] = 1;
    
    for(int i = 1; i < nax; ++i) {
        fact[i] = fact[i-1] * i % mod;
        rfact[i] = power(fact[i], mod-2); //no me preguntes porque
    }
    
    //calcular los binomios estos raros
    ll ans = binomCoeff(5, 3);
    
    //si queremos calcular el numero de paths en una grid, se suma b a la a:
    ans = binomCoeff(5+3, 3);
    
    return 0;
}
