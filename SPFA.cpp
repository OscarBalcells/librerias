#include <bits/stdc++.h>

using namespace std;

int main() {

    int S = 0; // -> source
    vi dist(n, oo); dist[S] = 0;
    queue<int> q; q.push(S);
    vi in_queue(n, 0); in_queue[S] = 1;
    
    while(!q.empty()) {
        int u = q.front(); q.pop(); in_queue[u] = 0;
        for(int j = 0; j < (int)AdjList[u].size(); j++) {
            int v = AdjList[u][j].first, weight_u_v = AdjList[u][j].second;
            if(dist[u] + weight_u_v < dist[v]) {
                if(!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = 1;
                }
            }
        }
    }
    
    //can be modified to detect negative weight cycles
    //if vertex enters queue more than v-1 times
    
    return 0;
}
