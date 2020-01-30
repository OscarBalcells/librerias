#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {

    int n;
    string a;
    
    getline(cin, a);
    n = int(a.size());
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if(i+1 < n) dp[i][i+1] = (a[i] == a[i+1] ? 2 : 1);
    }
    
    for(int l = n-1; l >= 0; --l) {
        for(int r = l+1; r < n; ++r) {
            if(a[l] == a[r]) {
                dp[l][r] = dp[l+1][r-1]+2;
            } 
            if(l-1 >= 0) dp[l][r] = max(dp[l][r], dp[l-1][r]);
            if(r-1 >= 0) dp[l][r] = max(dp[l][r], dp[l][r-1]);
        }
    }
    
    printf("%d\n", dp[0][n-1]);
}
