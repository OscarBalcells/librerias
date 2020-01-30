#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

char T[MAXN], P[MAXN]; // T = string, P = pattern
int b[MAXN], n, m; // b = back table, n = size of string, m = size of pattern

void kmpPreprocess() {
    
    int i = 0, j = -1;
    b[0] = -1;
    
    while(i < m) {
        
        while(j >= 0 && P[i] != P[j]) {
            j = b[j];
        }
        
        i++; j++;
        b[i] = j; 
    }
}

void kmpSearch() {
    
    int i = 0, j = 0;
    while(i < n) {
        while(j >= 0 && T[i] != P[j]) {
            j = b[j];
        }
        i++; j++;
        if(j == m) {
            printf("P is found at index %d in T\n", i-j);
            j = b[j];
        }
    }
    
}

int main() {
    
    string line;
    
    getline(cin, line);
    for(int i = 0; i < (int)line.size(); ++i) {
        T[i] = line[i];
    }

    getline(cin, line);
    for(int i = 0; i < (int)line.size(); ++i) {
        P[i] = line[i];
    }
    
    n = strlen(T);
    m = strlen(P);
    
    kmpPreprocess();
    kmpSearch();
    
    return 0;
}
