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

#define LARGE (1<<31)-1

using namespace std;

int N,M;
vector<int> adj[100001];
int vis[100001];
stack<int> s;

void dfs(int cur, bool add) {
	vis[cur] = 1;
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (vis[v]) continue;
		dfs(v,add);
	}
	if (add) s.push(cur);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			vis[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		int ans = 0;
		while (!s.empty()) s.pop();
		for (int i = 1; i <= N; i++) {
			if (vis[i]) continue;
			dfs(i,1);
		}
		for (int i = 1; i <= N; i++) vis[i] = 0;
		while (!s.empty()) {
			int u = s.top();
			s.pop();
			if (vis[u]) continue;
			dfs(u,0);
			ans++;
		}
		cout << "Case " << t << ": " << ans << endl;
	}
    return 0;
}
