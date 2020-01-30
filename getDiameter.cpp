#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vi> AdjList;

//finds the diameter of a tree
//and returns a vi of the path this diameter follows
//you can get the root vertex by calling
// r = diameter[diameter.size()/2]
// d = diameter.size() whereas s is the diameter

vector<int> get_diameter(int start_node) {
    
    queue<int> q;
    visited.assign(AdjList.size(), false);
    q.push(start_node);
    visited[start_node] = true;

    int far = start_node;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        far = u;

        for (const auto &item : AdjList[u]) {
            if (max(u, item) == max(b1, b2) && min(u, item) == min(b1, b2)) {
                continue;
            }

            int v = item;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    vector<int> parent(AdjList.size());
    
    q.push(far);
    visited.assign(AdjList.size(), false);
    visited[far] = true;
    parent[far] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        far = u;

        for (const auto &item : AdjList[u]) {
            if (min(b1, b2) == min(item, u) && max(b1, b2) == max(item, u)) {
                continue;
            }

            int v = item;
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    while (far != -1) {
        path.push_back(far);
        far = parent[far];
    }
    return path;
}

int main() {
    vi diameter = get_diameter(0); //start vertex is 0
    int root = diameter[diameter.size()/2]
    int size = diameter.size()
    return 0;
}
