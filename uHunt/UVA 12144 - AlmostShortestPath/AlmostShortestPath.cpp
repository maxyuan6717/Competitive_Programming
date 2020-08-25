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

int N,M,S,D,dist[500],p[500],len;
bool used[500][500], vis[500];
vii adj[500];

int dijkstra() {
    for (int i = 0; i < N; i++) dist[i] = LARGE;
    dist[S] = 0;
    priority_queue <pii,vii,greater<pii> > pq;
    pq.push(mp(0,S));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (u == D) return dist[D];
        for (int i = 0; i < adj[u].size(); i++) {
            int c = adj[u][i].second;
            int v = adj[u][i].first;
            if (used[u][v]) continue;
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u]+c;
                pq.push(mp(dist[v],v));
            }
        }
    }
    return -1;
}

void retrace() {
	for (int i = D; i != S; i = p[i]) {
		used[p[i]][i] = 1;
	}
}

void dfs(int u, int sum) {
	if (u == D && sum == len) {
		retrace();
		return;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		int c = adj[u][i].second;
		if (vis[v] || sum + c > len) continue;
		vis[v] = 1;
		p[v] = u;
		dfs(v,sum+c);
		p[v] = -1;
		vis[v] = 0;
	}
}

int main() {
	while (cin >> N >> M, N || M) {
		cin >> S >> D;
		//cout << N << " " << M << " " << S << " " << D << endl;
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			vis[i] = 0;
			p[i] = -1;
			for (int j = 0; j < N; j++) {
				used[i][j] = 0;
			}
		}
		for (int i = 0; i < M; i++) {
			int u,v,c;
			cin >> u >> v >> c;
			adj[u].push_back(mp(v,c));
		}
		len = dijkstra();
		if (len == -1) {
			cout << -1 << endl;
			continue;
		}
		vis[S] = 1;
		dfs(S,0);
		cout << dijkstra() << endl;
	}
    return 0;
}
