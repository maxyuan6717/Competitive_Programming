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

int N,M,start,cnt[51];
double l,r,mid,dis[51];
vii adj[51];
bool vis[51];

bool works(double x) {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		dis[i] = cnt[i] = 0;
		vis[i] = 1;
		q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].f;
			int c = adj[u][i].s;
			if (dis[u] + c - x < dis[v]) {
				dis[v] = dis[u] + c - x;
				if (vis[v]) continue;
				vis[v] = 1;
				q.push(v);
				cnt[v]++;
				if (cnt[v] > N) return 1;
			}
		}
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		cin >> N >> M;
		l =  r  = 0;
		for (int i = 1; i <= N; i++) adj[i].clear();
		for (int i = 0; i < M; i++) {
			int u,v,c;
			cin >> u >> v >> c;
			adj[u].push_back(mp(v,c));
			r = max(r,(double)c);
		}
		r += 10;
		if (!works(r)) {
			printf("No cycle found.\n");
			continue;
		}
		while (r-l > 1e-4) {
			mid = (l+r)/2;
			if (works(mid)) r = mid;
			else l = mid;
		}
		printf("%.2f\n",r);
	}
    return 0;
}
