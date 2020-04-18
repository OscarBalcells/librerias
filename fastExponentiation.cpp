#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
using ll = long long;

int myFasterPower(int a, int b) {
    
    int res = 1;
    
    while(b > 0) {
        
        if(b&1) {
            res = (ll)res * a % mod;
        }
        
        a = (ll)a *a % mod;
        b = b>>1;
    }
    
    return res;
}
