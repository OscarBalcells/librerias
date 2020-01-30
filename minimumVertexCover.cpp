#include <bits/dtsc++.h>

using namespace std;

const int nax = 1e5;

int memo[nax][2];
bool leaf[nax];
vector<vi> Children; //adjList to tell the kids of a node

int MVC(int v, int flag) {

    int ans = 0;
    if(memo[v][flag] != -1) return memo[v][flag];
    else if(leaf[v]) {
        ans = flag;
    } else if(flag == 0) {
        ans = 0;
        
        for(int i = 0; i < (int)Children[v].size(); ++i) {
            ans += MVC(Children[v][i], 1);
        }
    } else if(flag == 1) {
        ans = 1;
        for(int i = 0; i < (int)Children[v].size(); ++i) {
            ans += min(MVC(Children[v][i], 1), MVC(Children[v][i], 0));
        }
    }
    
    return memo[v][flag] = ans;

}

int main() {
    
    //fill Children AdjList
    //fill bool array leaf
    //fill all memo with -1
    
    int ans = min(MVC(root, 0),MVC(root,1));
    
    return 0;
}
