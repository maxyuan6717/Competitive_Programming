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
vii adj[500];

struct state {
	int u,d;
	bool b;
	state(int cur, int dis, bool back) {
		u = cur; d = dis; b = back;
	}
};

bool operator < (state a, state b) {
	return a.d > b.d;
}

int dijkstra() {
	int dis[500][2];
	for (int i = 0; i < N; i++) dis[i][0] = dis[i][1] = LARGE;
	dis[0][1] = 0;
	priority_queue<state> pq;
	pq.push(state(0,0,1));
	while (!pq.empty()) {
		int u = pq.top().u;
		int d = pq.top().d;
		bool b = pq.top().b;
		pq.pop();
		if (d != dis[u][b]) continue;
		if (u == N-1 && b) return dis[u][b];
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].f;
			int l = adj[u][i].s;
			if (dis[u][b] + l < dis[v][!b]) {
				dis[v][!b] = dis[u][b] + l;
				pq.push(state(v,dis[v][!b],!b));
			}
 		}
	}
	return -1;
}

int main() {
	int caseNum = 1;
	while (cin >> N >> M) {
		cout << "Set #" << caseNum++ << endl;
		for (int i = 0; i < N; i++) adj[i].clear();
		for (int i = 0; i < M; i++) {
			int u,v,l;
			cin >> u >> v >> l;
			adj[u].push_back(mp(v,l));
			adj[v].push_back(mp(u,l));
		}
		int ans = dijkstra();
		if (ans == -1) cout << '?' << endl;
		else cout << ans << endl;
	}
    return 0;
}
