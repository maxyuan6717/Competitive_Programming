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
typedef vector<pii> vii;

struct edge {
	int u,v,c;
};

int N,M,s,t,p;
vii adj1[10001];
vii adj2[10001];
int ds[10001];
int dt[10001];
vector<edge> edges;

void dijkstra() {
	priority_queue<pii,vii,greater<pii> > pq;
	ds[s] = 0;
	pq.push(mp(0,s));
	while (!pq.empty()) {
		int u = pq.top().second;
		int c = pq.top().first;
		pq.pop();
		for (int i = 0; i < adj1[u].size(); i++) {
			int v = adj1[u][i].first;
			int nc = adj1[u][i].second;
			if (c + nc < ds[v] && c + nc <= p) {
				ds[v] = c + nc;
				pq.push(mp(ds[v],v));
			}
		}
	}
	while (!pq.empty()) pq.pop();
	dt[t] = 0;
	pq.push(mp(0,t));
	while (!pq.empty()) {
		int u = pq.top().second;
		int c = pq.top().first;
		pq.pop();
		for (int i = 0; i < adj2[u].size(); i++) {
			int v = adj2[u][i].first;
			int nc = adj2[u][i].second;
			if (c + nc < dt[v] && c + nc <= p) {
				dt[v] = c + nc;
				pq.push(mp(dt[v],v));
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++) {
		//cout << t << endl;
		cin >> N >> M >> s >> t >> p;
		//cout << N << " " << M << " " << s << " " << t << " " << p << endl;
		edges.clear();
		for (int i = 1; i <= N; i++) {
			adj1[i].clear();
			adj2[i].clear();
			ds[i] = 1000000;
			dt[i] = 1000000;
		}
		for (int i = 0; i < M; i++) {
			int u,v,c;
			cin >> u >> v >> c;
			//cout << u << " " << v << " " << c << endl;
			adj1[u].push_back(mp(v,c));
			adj2[v].push_back(mp(u,c));
			edge e = {u,v,c};
			edges.push_back(e);
		}
		dijkstra();
		int ans = -1;
		//cout << p << endl;
		for (int i = 0; i < M; i++) {
			edge e = edges[i];
			int u = e.u;
			int v = e.v;
			int c = e.c;
			if (ds[u] + c + dt[v] > p) continue;
			//cout << ds[u] << " " << u << " " << c << " " << v << " " << dt[v] << endl;
			ans = max(ans,c);
		}
		if (ds[t] == LARGE || dt[s] == LARGE) ans = -1;
		cout << ans << endl;
	}
    
    return 0;
}
