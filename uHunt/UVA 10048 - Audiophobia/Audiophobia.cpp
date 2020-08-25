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

#define LARGE (1<<31)-1
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct edge {
	int s,d,c;
};

int N,M;
vector<edge> edges;
vii adj[101];
int vis[101];
int p[101];
int start,dest;
int ans = -1;

bool compare (edge a, edge b) {
	return a.c < b.c;
}

int find(int u) {
	if (p[u] == u) return u;
	else return p[u] = find(p[u]);
}

bool inSameSet(int u, int v) {
	return find(u) == find(v);
}

void unionSet(int u, int v) {
	p[find(u)] = find(v);
}

int dfs(int cur,int best) {
	vis[cur] = 1;
	if (cur == dest) {
		return best;
	}
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i].first;
		int c = adj[cur][i].second;
		if (vis[v]) continue;
		int ret = dfs(v,max(best,c));
		if (ret != -1) return ret;
	}
	return -1;
}

int main() {
	int Q;
	int caseNum = 1;
	cin >> N >> M >> Q;
	while (N || M || Q) {
		edges.clear();
		for (int i = 1; i <= N; i++) {
			p[i] = i;
			adj[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int x,y,z;
			cin >> x >> y >> z;
			edge e = {x,y,z};
			edges.push_back(e);
		}
		sort(edges.begin(),edges.end(),compare);
		for (int i = 0; i < edges.size(); i++) {
			edge e = edges[i];
			if (inSameSet(e.s,e.d)) continue;
			unionSet(e.s,e.d);
			adj[e.s].push_back(mp(e.d,e.c));
			adj[e.d].push_back(mp(e.s,e.c));
		}
		cout << "Case #" << caseNum++ << endl;
		for (int i = 0; i < Q; i++) {
			ans = -1;
			for (int i = 0; i <= N; i++) vis[i] = 0;
			cin >> start >> dest;
			int query = dfs(start,-1);
			if (query == -1) cout << "no path" << endl;
			else cout << query << endl;
		}
		cin >> N >> M >> Q;
		if (N || M || Q) cout << endl;
	}
    return 0;
}
