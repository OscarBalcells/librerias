#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9+7;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {

    int n = 10; //n-vertices
    vector<vii> AdjList(n);

    vi dist(n, oo); dist[0] = 0;
        
    //build dist table O(VE)
    for(int i = 0; i < n-1; ++i) {
        for(int u = 0; u < n; ++u) {
            for(int j = 0; j < (int)AdjList[u].size(); ++j) {
                ii v = AdjList[u][j];
                dist[v.first] = min(dist[v.first], dist[u]+v.second);
            }
        }
    }
    
    //check for negative cycle O(E)
    bool hasNegativeCycle = false;
    for(int u = 0; u < n; ++u) {
        for(int j = 0; j < (int)AdjList[u].size(); ++j) {
            ii v = AdjList[u][j];
            if(dist[v.first] > dist[u] + v.second) {
                //still not relaxed yet, so negative cycle
                hasNegativeCycle = true;
            }
        }
    }
    
    return 0;
}
