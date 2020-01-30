#include <bits/stdc++.h>

using namespace std;

//ONLY VALID FOR UNWEIGHTED GRAPHS!
//ONLY VALID FOR UNWEIGHTED GRAPHS!
//ONLY VALID FOR UNWEIGHTED GRAPHS!
//ONLY VALID FOR UNWEIGHTED GRAPHS!
//ONLY VALID FOR UNWEIGHTED GRAPHS!
//ONLY VALID FOR UNWEIGHTED GRAPHS!

void printPath(int u) { //WARNING! USING NON-GLOBAL VARIABLES
    if(u == s) { printf("%d",s); return; }
    printPath(p[u]) // recursive: to make output format: s -> ... -> t
    printf(" %d", u);
}

int main() {

    vector<int> dist(V,oo); dist[s] = 0;
    queue<int> q; q.push(s);
    vector<int> p; //parent
    
    while(!q.empty()) {
    
        int u = q.front(); q.pop();
        
        for(int i = 0; i < (int)AdjList[u].size(); ++i) {
            int v = AdjList[u][i]; //AdjList[n] are all vertices connected to n
            
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
    
    printPath(t), printf("\n"); //t is the destination vertex
    
    return 0;
}
