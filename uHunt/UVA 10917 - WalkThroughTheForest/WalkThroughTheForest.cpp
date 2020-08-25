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

int N,M;
vii adj[1001];
int dist[1001];
int memo[1001];

void dijkstra() {
	priority_queue<pii,vii,greater<pii> > pq;
	for (int i = 1 ; i <= N; i++) dist[i] = LARGE;
	dist[2] = 0;
	pq.push(mp(0,2));
	while (!pq.empty()) {
		int u = pq.top().s;
		pq.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int c = adj[u][i].s;
			int v = adj[u][i].f;
			if (dist[u] + c < dist[v]) {
				dist[v] = dist[u] + c;
				pq.push(mp(dist[v],v));
			}
		}
	}
}

int dfs(int v) {
	if (memo[v] != -1) return memo[v];
	int ret = 0;
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i].f;
		if (dist[u] > dist[v]) ret += dfs(u);
	}
	return memo[v] = ret;
}

int main() {
	while (cin >> N, N) {
		cin >> M;
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			memo[i] = -1;
		}
		for (int i = 0; i < M; i++) {
			int u,v,d;
			cin >> u >> v >> d;
			adj[u].push_back(mp(v,d));
			adj[v].push_back(mp(u,d));
		}
		dijkstra();
		memo[1] = 1;
		cout << dfs(2) << endl;
	}
    return 0;
}
