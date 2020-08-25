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
#include <climits>

#define LARGE INT_MAX
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

struct edge {
	int city,fuel,spent;
};

bool operator < (edge a, edge b) {
	return a.spent > b.spent;
}

int N,M;
int price[1001];
vii adj[1001];

int dijkstra(int c, int s, int e) {
	int dis[N][c+1];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= c; j++) {
			dis[i][j] = LARGE;
		}
	}
	dis[s][0] = 0;
	priority_queue<edge> pq;
	edge start = {s,0,0};
	pq.push(start);
	while (!pq.empty()) {
		edge u = pq.top();
		pq.pop();
		if (u.city == e) return u.spent;
		if (dis[u.city][u.fuel] < u.spent) continue;
		if (u.fuel < c && u.spent + price[u.city] < dis[u.city][u.fuel+1]) {
			dis[u.city][u.fuel+1] = u.spent + price[u.city];
			edge e = {u.city,u.fuel+1,u.spent + price[u.city]};
			pq.push(e);
		}
		for (int i = 0; i < adj[u.city].size(); i++) {
			int v = adj[u.city][i].second;
			int d = adj[u.city][i].first;
			if (u.fuel < d) continue;
			int after = u.fuel - d;
			if (u.spent < dis[v][after]) {
				dis[v][after] = u.spent;
				edge e = {v,after,u.spent};
				pq.push(e);
			}
		}

	}

	return -1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> price[i];
	for (int i = 0; i < M; i++) {
		int u,v,d;
		cin >> u >> v >> d;
		adj[u].push_back(mp(d,v));
		adj[v].push_back(mp(d,u));
	}
	int Q;
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		int c,s,e;
		cin >> c >> s >> e;
		int ans = dijkstra(c,s,e);
		if (ans == -1) cout << "impossible" << endl;
		else cout << ans << endl;
	}
    return 0;
}
