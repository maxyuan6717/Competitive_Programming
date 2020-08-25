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

int N,M;
vector<int> adj[101];
int color[101];
vector<int> seq;
vector<int> ans2;
int ans1 = 0;

bool check(int u) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (color[v]) return 0;
	}
	return 1;
}

void dfs(int cur) {
	if (cur == N+1) {
		if (seq.size() > ans1) {
			ans1 = seq.size();
			ans2 = seq;
		}
		return;
	}
	if (check(cur)) {
		color[cur] = 1;
		seq.push_back(cur);
		dfs(cur+1);
		seq.pop_back();
		color[cur] = 0;
	}
	dfs(cur+1);
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i <= N; i++) {
			color[i] = 0;
			adj[i].clear();
		}
		for (int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans1 = 0;
		ans2.clear();
		dfs(1);
		cout << ans1 << endl;
		for (int i = 0; i < ans2.size(); i++) {
			cout << ans2[i];
			if (i != ans2.size()-1) cout << " ";
		}
		cout << endl;
	}
    return 0;
}
