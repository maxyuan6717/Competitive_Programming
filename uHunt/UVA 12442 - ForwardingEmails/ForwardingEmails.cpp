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

int N;
int adj[50001];
int vis[50001];
int sum[50001];

int dfs(int cur) {
	int tempsum = 1;
	vis[cur] = 1;
	int v = adj[cur];
	if (!vis[v]) {
		tempsum += dfs(v);
	}
	sum[cur] = tempsum;
	vis[cur] = 0;
	return sum[cur];
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			int u,v;
			cin >> u >> v;
			adj[u] = v;
			vis[i] = 0;
			sum[i] = -1;
		}
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 1; i <= N; i++) {
			if (sum[i] != -1) continue;
			int pos = dfs(i);
			if (pos > ans1) {
				ans1 = pos;
				ans2 = i;
			}
		}
		cout << "Case " << t  << ": " << ans2 << ezndl;
	}
    
    return 0;
}
