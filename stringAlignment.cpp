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
const int oo = 1e9+7;
typedef pair<int,int> ii;

vector<vector<int>> dp;
vector<vector<ii>> parent;

void max_self(int& score, int new_score, ii pos, ii new_parent) {
    if(score < new_score) {
        score = new_score;
        parent[pos.first][pos.second] = new_parent;
    }
}

int main() {
    
    string a;
    string b;
    
    getline(cin, a);
    getline(cin, b);
    
    int m = (int)a.size(), n = (int)b.size();
    
    dp.assign(m+1, vector<int>(n+1, -oo));
    parent.assign(m+1, vector<ii>(n+1, ii(-1,-1))); 
    
    
    // dp[i][j] - the maximum score gotten
    // with both heights at i and j
    
    // solo podemos editar a!!!
    
    for(int i = 0; i <= m; ++i) {
        dp[i][0] = -i;
        parent[i][0] = ii(i-1, 0);
    }
    
    for(int i = 0; i <= n; ++i) {
        dp[0][i] = -i;
        parent[0][i] = ii(0, i-1);
    }
    
    parent[0][0] = ii(-1, -1);
    
    for(int r = 0; r < m; ++r) {
        for(int c = 0; c < n; ++c) {
            
            if(a[r] == b[c]) {
                max_self(dp[r+1][c+1], dp[r][c]+2, ii(r+1,c+1), ii(r, c));
            } else {
                max_self(dp[r+1][c], dp[r][c]-1, ii(r+1, c), ii(r, c)); // se borra el caracter 
                max_self(dp[r][c+1], dp[r][c]-1, ii(r, c+1), ii(r, c)); // se inserta caracter
                max_self(dp[r+1][c+1], dp[r][c]-1, ii(r+1, c+1), ii(r, c)); // se remplaza el caracter -> se pone el caracter b[c]
            }
        }
    }
    
    ii pos = ii(m, n); //parent[m][n];
    string s = "";
    
    while(pos != ii(-1, -1)) {
        ii new_pos = parent[pos.first][pos.second];
        if(new_pos != ii(-1, -1) && new_pos == ii(pos.first-1, pos.second-1)) {
            if(b[new_pos.second] == a[new_pos.first]) {
                s += b[new_pos.second];
            } else {
                s += ']';
                s += b[new_pos.second];
                s += '[';
            }
        } else if(new_pos != ii(-1, -1) && new_pos == ii(pos.first-1, pos.second)) {
            s += '_';
        } else if(new_pos != ii(-1, -1) && new_pos == ii(pos.first, pos.second-1)) {
            s += ']';
            s += b[new_pos.second];
            s += '[';
        }
        pos = new_pos;
    } 
    
    reverse(s.begin(), s.end());
    
    cout << s << endl;
}
