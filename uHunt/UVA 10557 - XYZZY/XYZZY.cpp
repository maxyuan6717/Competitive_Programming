#include <iostream>
#include <fstream>
#include <string>
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

struct edge {
	int u,v,c;
};

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N;
vector<edge> edges;
vector<int> adj[101];
int energy[101];
int dis[101];
int vis[101];

void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (vis[v]) continue;
		dfs(v);
	}
}

int bellmanford() {
	dis[1] = -100;
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < edges.size(); j++) {
			edge e = edges[j];
			int u = e.u, v = e.v, c = e.c;
			if (dis[u] >= 0) continue;
			dis[v] = min(dis[v],dis[u]+c);
		}
	}
	int ans = 0;
	for (int i = 0; i < edges.size(); i++) {
		edge e = edges[i];
		int u = e.u, v = e.v, c = e.c;
		if (dis[u] >= 0) continue;
		if (dis[u] + c < dis[v]) {
			for (int j = 1; j <= N; j++) vis[j] = 0;
			dfs(u);
			ans |= vis[N];
		}
	}
	return (dis[N] < 0 || ans);
}

int main() {
	cin >> N;
	while (N != -1) {
		edges.clear();
		for (int i = 1; i <= N; i++) {
			dis[i] = LARGE;
			cin >> energy[i];
			adj[i].clear();
			int M;
			cin >> M;
			for (int j = 0; j < M; j++) {
				int v;
				cin >> v;
				adj[i].push_back(v);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				int v = adj[i][j];
				edge e = {i,v,-energy[v]};
				edges.push_back(e);
			}
		}
		string ans[2] = {"hopeless","winnable"};
		cout << ans[bellmanford()] << endl;
		cin >> N;
	}
    return 0;
}
