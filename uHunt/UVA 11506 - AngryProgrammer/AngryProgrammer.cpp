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

int M,W;
int res[102][102];
int vis[102];
int p[102];

int bfs() {
	for (int i = 1; i <= 2*M+1; i++) vis[i] = p[i] = 0;
	p[3] = -1;
	vis[3] = 1;
	queue<int> q;
	q.push(3);
	while (!q.empty()) {
		int u = q.front();
		//cout << u << endl;
		q.pop();
		if (u == 2*M) return 1;
		for (int v = 1; v <= 2*M; v++) {
			if (vis[v] || !res[u][v]) continue;
			q.push(v);
			vis[v] = 1;
			p[v] = u;
		}
	}
	return 0;
}

int ek() {
	int ans = 0;
	while (bfs()) {
		int flow = LARGE;
		for (int i = 2*M; i != 3; i = p[i]) {
			flow = min(flow,res[p[i]][i]);
		}
		for (int i = 2*M; i != 3; i = p[i]) {
			res[p[i]][i] -= flow;
			res[i][p[i]] += flow;
		}
		ans += flow;
	}
	return ans;
}

int main() {
	cin >> M >> W;
	while (M || W) {
		memset(res,0,sizeof(res));
		for (int i = 0; i < M-2; i++) {
			int u,c;
			cin >> u >> c;
			res[2*u][2*u+1] = c;
		}
		for (int i = 0; i < W; i++) {
			int u,v,c;
			cin >> u >> v >> c;
			res[2*u+1][2*v] = c;
			res[2*v+1][2*u] = c;
		}
		cout << ek() << endl;
		cin >> M >> W;
	}
    return 0;
}
