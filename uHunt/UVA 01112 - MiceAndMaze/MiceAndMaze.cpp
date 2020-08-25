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

typedef pair<int,int> pii;

struct point {
	int v,dis;
};

bool operator < (point a, point b) {
	return a.dis > b.dis;
}

int N,E,T,M;
vector<pii> adj[101];
int dis[101];

void dijkstra() {
	dis[E] = 0;
	priority_queue<point> pq;
	point start = {E,0};
	pq.push(start);
	while (!pq.empty()) {
		point u = pq.top();
		pq.pop();
		for (int i = 0; i < adj[u.v].size(); i++) {
			int v = adj[u.v][i].first;
			int c = adj[u.v][i].second;
			if (dis[u.v] + c < dis[v] && dis[u.v] + c <= T) {
				dis[v] = dis[u.v] + c;
				point nv = {v,c};
				pq.push(nv);
			}
		}
	}
}

int main() {
	int C;
	cin >> C;
	for (int t = 0; t < C; t++) {
		cin >> N >> E >> T >> M;
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			dis[i] = LARGE;
		}
		for (int i = 0; i < M; i++) {
			int a,b,c;
			cin >> a >> b >> c;
			adj[b].push_back(mp(a,c));
		}
		dijkstra();
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (dis[i] <= T) ans++;
		}
		cout << ans << endl;
		if (t != C-1) cout << endl;
	}
    
    return 0;
}
