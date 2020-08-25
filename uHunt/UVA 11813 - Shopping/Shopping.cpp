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

#define LARGE 1e18
#define mp make_pair
#define f first
#define s second

using namespace std;

typedef pair<int,long> pii;
typedef vector<pii> vii;

int N,M,S;
vii adj[100000];
long long dis1[11][11];
long long dp[11][1<<11];
long long dis2[100000];
int num[100000];
vector<int> stores;

void dijkstra(int start) {
	priority_queue<pii,vii,greater<pii> > pq;
	for (int i = 0; i < N; i++) dis2[i] = LARGE;
	dis2[stores[start]] = 0;
	pq.push(mp(0,stores[start]));
	while (!pq.empty()) {
		int u = pq.top().s;
		pq.pop();
		if (num[u] > -1) {
			dis1[start][num[u]] = dis2[u];
		}
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].f;
			long long c = adj[u][i].s;
			if (dis2[u] + c < dis2[v]) {
				dis2[v] = dis2[u] + c;
				//cout << u << " " << v << " " << dis2[v] << endl;
				pq.push(mp(dis2[v],v));
			}
		}
	}
}

long long tsp(int cur, int vis) {
	if (vis == (1<<S)-1) {
		return dis1[cur][0];
	}
	if (dp[cur][vis] != -1) return dp[cur][vis];
	long long ans = LARGE;
	for (int i = 0; i < S; i++) {
		if ((vis & 1<<i) || i == cur) continue;
		ans = min(ans,dis1[cur][i] + tsp(i,vis|1<<i));
	}
	return dp[cur][vis] = ans;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		stores.clear();
		memset(num,-1,sizeof(num));
		for (int i = 0; i < N; i++) adj[i].clear();
		for (int i = 0; i < M; i++) {
			int u,v;
			long long d;
			cin >> u >> v >> d;
			adj[u].push_back(mp(v,d));
			adj[v].push_back(mp(u,d));
		}
		cin >> S;
		stores.push_back(0);
		num[0] = 0;
		for (int i = 1; i <= S; i++) {
			int store;
			cin >> store;
			stores.push_back(store);
			num[store] = i;
		}
		S++;
		for (int i = 0; i < S; i++) {
			for (int j = 0; j < S; j++) {
				dis1[i][j] = LARGE;
				if (i == j) dis1[i][j] = 0;
			}
		}
		for (int i = 0; i < S; i++) dijkstra(i);
		/*for (int i = 0; i < S; i++) {
			for (int j = 0; j < S; j++) {
				cout << dis1[i][j] << " ";
			}
			cout << endl;
		}*/
		for (int i = 0; i < S; i++) {
			for (int j = 0; j < 1<<S; j++) {
				dp[i][j] = -1;
			}
		}
		cout << tsp(0,1) << endl;
	}
    return 0;
}
