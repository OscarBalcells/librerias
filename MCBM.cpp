#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long int ll;

vi match, vis;
vector<vi> AdjList;

int Aug(int l) {
		
		if(vis[l]) return 0;
		vis[l] = 1;
		
		for(int j = 0; j < (int)AdjList[l].size(); ++j) {
				int r = AdjList[l][j];
				if(match[r] == -1 || Aug(match[r])) {
						match[r] = l; return 1;
				}
		}
		
		return 0;
	
}

int main() {
	
		int MCBM = 0;
		
		match.assign(V, -1); //all unmatched at the beginning
		
		for(int l = 0; l < n; l++) { //left side only
				vis.assign(n, 0);
				MCBM += Aug(l);
		}

		printf("Found %d matchings\n", MCBM);

}
