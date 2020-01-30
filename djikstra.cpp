#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

int main() {

    vector<int> dist(V, oo); dist[s] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq; 
    pq.push(ii(0, s));
    
    while(!pq.empty()) {
        
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        
        if(d > dist[u]) continue;
        
        for(int i = 0; i < (int)AdjList[u].size(); ++i) {
            ii v = AdjList[u][i]; // (vertex, weight)
            
            if(dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }

    return 0;
}
