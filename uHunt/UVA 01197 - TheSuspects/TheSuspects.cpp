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

vector<int> adj[30001];
int ans = 0;
bitset<30001> vis;

void dfs(int cur) {
	for (int i = 0; i < adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (vis[v]) continue;
		ans++;
		vis[v] = 1;
		dfs(v);
	}
}

int main() {
	int N,M;
	cin >> N >> M;
	while (N || M) {
		for (int i = 0; i <= 30000; i++) {
			adj[i].clear();
			vis[i] = 0;
		}
		for (int m = 0; m < M; m++) {
			int num;
			int v;
			cin >> num >> v;
			for (int i = 1; i < num; i++) {
				int u;
				cin >> u;
				adj[v].push_back(u);
				adj[u].push_back(v);
			}
		}
		ans = 1;
		vis[0] = 1;
		dfs(0);
		cout << ans << endl;
		cin >> N >> M;
	}
    return 0;
}
