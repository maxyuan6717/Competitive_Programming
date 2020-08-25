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
#define s second
#define f first

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;

int N,H,M,num;
const int lim = 600;
vector<int> hotels;
vii adj[10001];
int dist[10001];
int dist2[101];
int dis[101][101];
int hotel[10001];
bool edge[101][101];
bool vis[101];

void dijkstra(int start) {
	priority_queue<pii,vii,greater<pii> > pq;
	for (int i = 0; i <= N; i++) dist[i] = LARGE;
	dist[hotels[start]] = 0;
	pq.push(mp(0,hotels[start]));
	while (!pq.empty()) {
		int u = pq.top().s;
		int d = dist[u];
		pq.pop();
		if (d > 600) return;
		if (hotel[u] > -1) {
			dis[start][hotel[u]] = d;
		}
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].f;
			int c = adj[u][i].s;
			if (d + c < dist[v]) {
				dist[v] = d + c;
				pq.push(mp(dist[v],v));
			}
		}
	}
}

int bfs() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (hotels[u] == N) return dist2[u];
		for (int v = 0; v < H; v++) {
			if (dist2[v] != LARGE || !edge[u][v]) continue;
			int hr = dist2[u];
			if (hotels[v] != N) hr++;
			q.push(v);
			dist2[v] = hr;
		}
	}
	return -1;
}

int main() {
	while (cin >> N, N) {
		cin >> H;
		hotels.clear();
		memset(hotel,-1,sizeof(hotel));
		hotels.push_back(1);
		hotel[1] = 0;
		for (int i = 0; i <= N; i++) adj[i].clear();
		for (int i = 1; i <= H; i++) {
			cin >> num;
			hotels.push_back(num);
			hotel[num] = i;
		}
		hotels.push_back(N);
		hotel[N] = H+1;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int u,v,d;
			cin >> u >> v >> d;
			adj[u].push_back(mp(v,d));
			adj[v].push_back(mp(u,d));
		}
		H+=2;
		for (int i = 0; i < H; i++) {
			dist2[i] = LARGE;
			for (int j = 0; j < H; j++) {
				dis[i][j] = LARGE;
			}
		}
		for (int i = 0; i < H; i++) dijkstra(i);
		for (int i = 0; i < H; i++) {
			vis[i] = 0;
			for (int j = 0; j < H; j++) {
				edge[i][j] = 0;
				if (dis[i][j] <= lim) edge[i][j] = 1;
			}
		}
		dist2[0] = 0;
		cout << bfs() << endl;
	}
    return 0;
}
