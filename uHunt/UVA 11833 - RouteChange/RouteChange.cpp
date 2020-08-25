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

int N,M,C,K,dis[250],dis2[250],arr[250][250];
vii adj[250];

void dijkstra(int s) {
	for (int i = 0; i < N; i++) dis[i] = LARGE;
	priority_queue<pii,vii,greater<pii> > pq;
	dis[s] = 0;
	pq.push(mp(0,s));
	while (!pq.empty()) {
		int u = pq.top().second;
		//cout << u << " " << dis[u] << endl;
		pq.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].f;
			int c = adj[u][i].s;
			if (dis[u] + c < dis[v]) {
				dis[v] = dis[u] + c;
				pq.push(mp(dis[v],v));
			}
		}
	}
}

int main() {
	while (cin >> N >> M >> C >> K, N || M || C || K) {
		for (int i = 0; i < N; i++) adj[i].clear();
		for (int i = 0; i < M; i++) {
			int u,v,p;
			cin >> u >> v >> p;
			if (u < C && v < C) {
				if (u == v+1) adj[v].push_back(mp(u,p));
				else if (v == u+1) adj[u].push_back(mp(v,p));
				continue;
			}
			else if (u < C && v>u) {
				adj[v].push_back(mp(u,p));
				continue;
			}
			else if (v < C && u>v) {
				adj[u].push_back(mp(v,p));
				continue;
			}
			adj[u].push_back(mp(v,p));
			adj[v].push_back(mp(u,p));
			arr[u][v] = arr[v][u] = p;
		}
		for (int i = C-2; i >= 0; i--) {
			dis2[i] = dis2[i+1] + arr[i+1][i];
		}
		dijkstra(K);
		cout << dis[C-1] << endl;
	}
    return 0;
}
