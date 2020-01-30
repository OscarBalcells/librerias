#include <bits/stdc++.h>

using namespace std;

const int n = 500;

void printPath(int i, int j) {
    if(i != j) printPath(i, p[i][j]);
    printf(" %d", j);
}

int main() {
    
    int AdjMatrix[n][n];
    int p[n][n];
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            p[i][j] = i;
        }
    }
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(AdjMatrix[i][j] > AdjMatrix[i][k] + AdjMatrix[k][j]) {
                    AdjMatrix[i][j] = AdjMatrix[i][k] + AdjMatrix[k][j];
                    p[i][k] = p[k][j];
                }
            }
        }
    }
    
    
    
    return 0;
}
