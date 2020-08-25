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
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct edge {
	int u,v,c;
};

int N,M,p[1000001];
bool vis[1000001];
vector<int> adj[1000001];
vector<edge> edges;

bool comp (edge a, edge b) {
	return a.c < b.c;
}

int find (int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}

void join (int a, int b) {
	p[find(a)] = find(b);
}

bool inSame(int a, int b) {
	return find(a) == find(b);
}

void dfs(int u) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (vis[v]) continue;
		vis[v] = 1;
		dfs(v);
	}
}

bool reachAll() {
	for (int i = 0; i < N; i++) if (!vis[i]) return 0;
	return 1;
}

int main() {
	while (cin >> N >> M, N || M) {
		edges.clear();
		for (int i = 0; i < N; i++) {
			p[i] = i;
			vis[i] = 0;
			adj[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int u,v,c;
			cin >> u >> v >> c;
			edge e = {u,v,c};
			edges.push_back(e);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0);
		if (!reachAll()) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		sort(edges.begin(),edges.end(),comp);
		int ans = 0;
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSame(e.u,e.v)) continue;
			join(e.u,e.v);
			ans = max(ans,e.c);
		}
		cout << ans << endl;
	}
    return 0;
}
