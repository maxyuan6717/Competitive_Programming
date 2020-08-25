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
int arr[101][101];
int vis[101];
stack<int> ans;

void dfs(int cur) {
	vis[cur] = 1;
	for (int i = 1; i <= N; i++) {
		if (vis[i] || !arr[cur][i]) continue;
		dfs(i);
	}
	ans.push(cur);
}

void topologicalSort() {
	while (!ans.empty()) ans.pop();
	for (int i = 1; i <= N; i++) {
		vis[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
		if (!ans.empty()) cout << " ";
	}
}

int main() {
	cin >> N >> M;
	while (N || M) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			arr[u][v] = 1;
		}
		topologicalSort();
		cout << endl;
		cin >> N >> M;
	}
    return 0;
}
