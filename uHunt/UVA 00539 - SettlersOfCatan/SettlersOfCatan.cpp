#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <bitset>
#include <iomanip>
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,M,ans = 0;
vector<int> adj[25];
bool vis[25][25];

void dfs(int u, int len) {
	//cout << u << " " << len << endl;
	ans = max(ans,len);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (vis[u][v]) continue;
		vis[u][v] = 1;
		vis[v][u] = 1;
		dfs(v,len+1);
		vis[u][v] = 0;
		vis[v][u] = 0;
	}
}

int main() {
	while (cin >> N >> M, N || M) {
		for (int i = 0; i < N; i++) adj[i].clear();
		for (int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					vis[j][k] = 0;
			dfs(i,0);
		}
		cout << ans << endl;
	}
    return 0;
}
